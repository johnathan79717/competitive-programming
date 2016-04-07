{-# LANGUAGE CPP #-}
{-# LANGUAGE DeriveDataTypeable #-}

import Data.Maybe
import Data.Char
import Control.Monad
import Prelude hiding (readList)
import Data.Array.IO
import qualified Data.ByteString.Char8 as B



-----------------------------------------------------------------------------
-- |
-- Copyright   :  (c) Edward Kmett 2010-2015
-- License     :  BSD-style
-- Maintainer  :  ekmett@gmail.com
-- Stability   :  experimental
-- Portability :  portable
--
-- An efficient, asymptotically optimal, implementation of a priority queues
-- extended with support for efficient size, and `Data.Foldable`
--
-- /Note/: Since many function names (but not the type name) clash with
-- "Prelude" names, this module is usually imported @qualified@, e.g.
--
-- >  import Data.Heap (Heap)
-- >  import qualified Data.Heap as Heap
--
-- The implementation of 'Heap' is based on /bootstrapped skew binomial heaps/
-- as described by:
--
--    * G. Brodal and C. Okasaki , <http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.48.973 "Optimal Purely Functional Priority Queues">,
--      /Journal of Functional Programming/ 6:839-857 (1996)
--
-- All time bounds are worst-case.
-----------------------------------------------------------------------------


import Prelude hiding
    ( map
    , span, dropWhile, takeWhile, break, filter, take, drop, splitAt
    , foldr, minimum, replicate, mapM
    , concatMap
    )
import qualified Data.List as L
import Control.Applicative (Applicative(pure))
import Control.Monad (liftM)
import Data.Monoid (Monoid(mappend, mempty))
import Data.Foldable hiding (minimum, concatMap, foldr)
import Data.Function (on)
import Data.Data (DataType, Constr, mkConstr, mkDataType, Fixity(Prefix), Data(..), constrIndex)
import Data.Typeable (Typeable)
import Text.Read
import Text.Show
import qualified Data.Traversable as Traversable
import Data.Traversable (Traversable)

-- The implementation of 'Heap' must internally hold onto the dictionary entry for ('<='),
-- so that it can be made 'Foldable'. Confluence in the absence of incoherent instances
-- is provided by the fact that we only ever build these from instances of 'Ord' a (except in the case of 'groupBy')


-- | A min-heap of values of type @a@.
data Heap a
  = Empty
  | Heap {-# UNPACK #-} !Int (a -> a -> Bool) {-# UNPACK #-} !(Tree a)
  deriving Typeable

heapDataType :: DataType
heapDataType = mkDataType "Data.Heap.Heap" [fromListConstr]

fromListConstr :: Constr
fromListConstr = mkConstr heapDataType "fromList" [] Prefix

instance Eq (Heap a) where
  Empty == Empty = True
  Empty == Heap{} = False
  Heap{} == Empty = False
  a@(Heap s1 leq _) == b@(Heap s2 _ _) = s1 == s2 && go leq (toList a) (toList b)
    where
      go f (x:xs) (y:ys) = f x y && f y x && go f xs ys
      go _ [] [] = True
      go _ _ _ = False

instance Ord (Heap a) where
  Empty `compare` Empty = EQ
  Empty `compare` Heap{} = LT
  Heap{} `compare` Empty = GT
  a@(Heap _ leq _) `compare` b = go leq (toList a) (toList b)
    where
      go f (x:xs) (y:ys) =
          if f x y
          then if f y x
               then go f xs ys
               else LT
          else GT
      go f [] []    = EQ
      go f [] (_:_) = LT
      go f (_:_) [] = GT



-- | /O(1)/. The empty heap
--
-- @'empty' â‰¡ 'fromList' []@
--
-- >>> size empty
-- 0
empty :: Heap a
empty = Empty
{-# INLINE empty #-}

-- | /O(1)/. A heap with a single element
--
-- @
-- 'singleton' x â‰¡ 'fromList' [x]
-- 'singleton' x â‰¡ 'insert' x 'empty'
-- @
--
-- >>> size (singleton "hello")
-- 1
singleton :: Ord a => a -> Heap a
singleton = singletonWith (<=)
{-# INLINE singleton #-}

singletonWith :: (a -> a -> Bool) -> a -> Heap a
singletonWith f a = Heap 1 f (Node 0 a Nil)
{-# INLINE singletonWith #-}

-- | /O(1)/. Insert a new value into the heap.
--
-- >>> insert 2 (fromList [1,3])
-- fromList [1,2,3]
--
-- @
-- 'insert' x 'empty' â‰¡ 'singleton' x
-- 'size' ('insert' x xs) â‰¡ 1 + 'size' xs
-- @
insert :: Ord a => a -> Heap a -> Heap a
insert = insertWith (<=)
{-# INLINE insert #-}

insertWith :: (a -> a -> Bool) -> a -> Heap a -> Heap a
insertWith leq x Empty = singletonWith leq x
insertWith leq x (Heap s _ t@(Node _ y f))
  | leq x y   = Heap (s+1) leq (Node 0 x (t `Cons` Nil))
  | otherwise = Heap (s+1) leq (Node 0 y (skewInsert leq (Node 0 x Nil) f))
{-# INLINE insertWith #-}

-- | /O(1)/. Meld the values from two heaps into one heap.
--
-- >>> union (fromList [1,3,5]) (fromList [6,4,2])
-- fromList [1,2,6,4,3,5]
-- >>> union (fromList [1,1,1]) (fromList [1,2,1])
-- fromList [1,1,1,2,1,1]
union :: Heap a -> Heap a -> Heap a
union Empty q = q
union q Empty = q
union (Heap s1 leq t1@(Node _ x1 f1)) (Heap s2 _ t2@(Node _ x2 f2))
  | leq x1 x2 = Heap (s1 + s2) leq (Node 0 x1 (skewInsert leq t2 f1))
  | otherwise = Heap (s1 + s2) leq (Node 0 x2 (skewInsert leq t1 f2))
{-# INLINE union #-}

-- | /O(log n)/. Create a heap consisting of multiple copies of the same value.
--
-- >>> replicate 'a' 10
-- fromList "aaaaaaaaaa"
replicate :: Ord a => a -> Int -> Heap a
replicate x0 y0
  | y0 < 0 = error "Heap.replicate: negative length"
  | y0 == 0 = mempty
  | otherwise = f (singleton x0) y0
  where
    f x y
        | even y = f (union x x) (quot y 2)
        | y == 1 = x
        | otherwise = g (union x x) (quot (y - 1) 2) x
    g x y z
        | even y = g (union x x) (quot y 2) z
        | y == 1 = union x z
        | otherwise = g (union x x) (quot (y - 1) 2) (union x z)
{-# INLINE replicate #-}

-- | Provides both /O(1)/ access to the minimum element and /O(log n)/ access to the remainder of the heap.
-- This is the same operation as 'viewMin'
--
-- >>> uncons (fromList [2,1,3])
-- Just (1,fromList [2,3])
uncons :: Heap a -> Maybe (a, Heap a)
uncons Empty = Nothing
uncons l@(Heap _ _ t) = Just (root t, deleteMin l)
{-# INLINE uncons #-}

-- | Same as 'uncons'
viewMin :: Heap a -> Maybe (a, Heap a)
viewMin = uncons
{-# INLINE viewMin #-}

-- | /O(1)/. Assumes the argument is a non-'null' heap.
--
-- >>> minimum (fromList [3,1,2])
-- 1
minimum :: Heap a -> a
minimum Empty = error "Heap.minimum: empty heap"
minimum (Heap _ _ t) = root t
{-# INLINE minimum #-}

trees :: Forest a -> [Tree a]
trees (a `Cons` as) = a : trees as
trees Nil = []

-- | /O(log n)/. Delete the minimum key from the heap and return the resulting heap.
--
-- >>> deleteMin (fromList [3,1,2])
-- fromList [2,3]
deleteMin :: Heap a -> Heap a
deleteMin Empty = Empty
deleteMin (Heap _ _ (Node _ _ Nil)) = Empty
deleteMin (Heap s leq (Node _ _ f0)) = Heap (s - 1) leq (Node 0 x f3)
  where
    (Node r x cf, ts2) = getMin leq f0
    (zs, ts1, f1) = splitForest r Nil Nil cf
    f2 = skewMeld leq (skewMeld leq ts1 ts2) f1
    f3 = L.foldr (skewInsert leq) f2 (trees zs)
{-# INLINE deleteMin #-}

-- | /O(log n)/. Adjust the minimum key in the heap and return the resulting heap.
--
-- >>> adjustMin (+1) (fromList [1,2,3])
-- fromList [2,2,3]
adjustMin :: (a -> a) -> Heap a -> Heap a
adjustMin _ Empty = Empty
adjustMin f (Heap s leq (Node r x xs)) = Heap s leq (heapify leq (Node r (f x) xs))
{-# INLINE adjustMin #-}

type ForestZipper a = (Forest a, Forest a)

zipper :: Forest a -> ForestZipper a
zipper xs = (Nil, xs)
{-# INLINE zipper #-}

emptyZ :: ForestZipper a
emptyZ = (Nil, Nil)
{-# INLINE emptyZ #-}

-- leftZ :: ForestZipper a -> ForestZipper a
-- leftZ (x :> path, xs) = (path, x :> xs)

rightZ :: ForestZipper a -> ForestZipper a
rightZ (path, x `Cons` xs) = (x `Cons` path, xs)
{-# INLINE rightZ #-}

adjustZ :: (Tree a -> Tree a) -> ForestZipper a -> ForestZipper a
adjustZ f (path, x `Cons` xs) = (path, f x `Cons` xs)
adjustZ _ z = z
{-# INLINE adjustZ #-}

rezip :: ForestZipper a -> Forest a
rezip (Nil, xs) = xs
rezip (x `Cons` path, xs) = rezip (path, x `Cons` xs)

-- assumes non-empty zipper
rootZ :: ForestZipper a -> a
rootZ (_ , x `Cons` _) = root x
rootZ _ = error "Heap.rootZ: empty zipper"
{-# INLINE rootZ #-}

minZ :: (a -> a -> Bool) -> Forest a -> ForestZipper a
minZ _ Nil = emptyZ
minZ f xs = minZ' f z z
    where z = zipper xs
{-# INLINE minZ #-}

minZ' :: (a -> a -> Bool) -> ForestZipper a -> ForestZipper a -> ForestZipper a
minZ' _ lo (_, Nil) = lo
minZ' leq lo z = minZ' leq (if leq (rootZ lo) (rootZ z) then lo else z) (rightZ z)

heapify :: (a -> a -> Bool) -> Tree a -> Tree a
heapify _ n@(Node _ _ Nil) = n
heapify leq n@(Node r a as)
  | leq a a' = n
  | otherwise = Node r a' (rezip (left, heapify leq (Node r' a as') `Cons` right))
  where
    (left, Node r' a' as' `Cons` right) = minZ leq as


-- | /O(n)/. Build a heap from a list of values.
--
-- @
-- 'fromList' '.' 'toList' â‰¡ 'id'
-- 'toList' '.' 'fromList' â‰¡ 'sort'
-- @

-- >>> size (fromList [1,5,3])
-- 3
fromList :: Ord a => [a] -> Heap a
fromList = foldr insert mempty
{-# INLINE fromList #-}

fromListWith :: (a -> a -> Bool) -> [a] -> Heap a
fromListWith f = foldr (insertWith f) mempty
{-# INLINE fromListWith #-}

-- | /O(n log n)/. Perform a heap sort
sort :: Ord a => [a] -> [a]
sort = toList . fromList
{-# INLINE sort #-}

instance Monoid (Heap a) where
  mempty = empty
  {-# INLINE mempty #-}
  mappend = union
  {-# INLINE mappend #-}

-- | /O(n)/. Returns the elements in the heap in some arbitrary, very likely unsorted, order.
--
-- >>> toUnsortedList (fromList [3,1,2])
-- [1,3,2]
--
-- @'fromList' '.' 'toUnsortedList' â‰¡ 'id'@
toUnsortedList :: Heap a -> [a]
toUnsortedList Empty = []
toUnsortedList (Heap _ _ t) = foldMap return t
{-# INLINE toUnsortedList #-}

instance Foldable Heap where
  foldMap _ Empty = mempty
  foldMap f l@(Heap _ _ t) = f (root t) `mappend` foldMap f (deleteMin l)

-- | /O(1)/. Is the heap empty?
--
-- >>> null empty
-- True
--
-- >>> null (singleton "hello")
-- False
null :: Heap a -> Bool
null Empty = True
null _ = False
{-# INLINE null #-}


-- | /O(1)/. The number of elements in the heap.
--
-- >>> size empty
-- 0
-- >>> size (singleton "hello")
-- 1
-- >>> size (fromList [4,1,2])
-- 3
size :: Heap a -> Int
size Empty = 0
size (Heap s _ _) = s
{-# INLINE size #-}


-- we hold onto the children counts in the nodes for /O(1)/ 'size'
data Tree a = Node
  { rank :: {-# UNPACK #-} !Int
  , root :: a
  , _forest :: !(Forest a)
  } deriving (Show,Read,Typeable)

data Forest a = !(Tree a) `Cons` !(Forest a) | Nil
  deriving (Show,Read,Typeable)
infixr 5 `Cons`

instance Functor Tree where
  fmap f (Node r a as) = Node r (f a) (fmap f as)

instance Functor Forest where
  fmap f (a `Cons` as) = fmap f a `Cons` fmap f as
  fmap _ Nil = Nil

-- internal foldable instances that should only be used over commutative monoids
instance Foldable Tree where
  foldMap f (Node _ a as) = f a `mappend` foldMap f as

-- internal foldable instances that should only be used over commutative monoids
instance Foldable Forest where
  foldMap f (a `Cons` as) = foldMap f a `mappend` foldMap f as
  foldMap _ Nil = mempty

link :: (a -> a -> Bool) -> Tree a -> Tree a -> Tree a
link f t1@(Node r1 x1 cf1) t2@(Node r2 x2 cf2) -- assumes r1 == r2
  | f x1 x2   = Node (r1+1) x1 (t2 `Cons` cf1)
  | otherwise = Node (r2+1) x2 (t1 `Cons` cf2)

skewLink :: (a -> a -> Bool) -> Tree a -> Tree a -> Tree a -> Tree a
skewLink f t0@(Node _ x0 cf0) t1@(Node r1 x1 cf1) t2@(Node r2 x2 cf2)
  | f x1 x0 && f x1 x2 = Node (r1+1) x1 (t0 `Cons` t2 `Cons` cf1)
  | f x2 x0 && f x2 x1 = Node (r2+1) x2 (t0 `Cons` t1 `Cons` cf2)
  | otherwise          = Node (r1+1) x0 (t1 `Cons` t2 `Cons` cf0)

ins :: (a -> a -> Bool) -> Tree a -> Forest a -> Forest a
ins _ t Nil = t `Cons` Nil
ins f t (t' `Cons` ts) -- assumes rank t <= rank t'
  | rank t < rank t' = t `Cons` t' `Cons` ts
  | otherwise = ins f (link f t t') ts

uniqify :: (a -> a -> Bool) -> Forest a -> Forest a
uniqify _ Nil = Nil
uniqify f (t `Cons` ts) = ins f t ts

unionUniq :: (a -> a -> Bool) -> Forest a -> Forest a -> Forest a
unionUniq _ Nil ts = ts
unionUniq _ ts Nil = ts
unionUniq f tts1@(t1 `Cons` ts1) tts2@(t2 `Cons` ts2) = case compare (rank t1) (rank t2) of
  LT -> t1 `Cons` unionUniq f ts1 tts2
  EQ -> ins f (link f t1 t2) (unionUniq f ts1 ts2)
  GT -> t2 `Cons` unionUniq f tts1 ts2

skewInsert :: (a -> a -> Bool) -> Tree a -> Forest a -> Forest a
skewInsert f t ts@(t1 `Cons` t2 `Cons`rest)
  | rank t1 == rank t2 = skewLink f t t1 t2 `Cons` rest
  | otherwise = t `Cons` ts
skewInsert _ t ts = t `Cons` ts
{-# INLINE skewInsert #-}

skewMeld :: (a -> a -> Bool) -> Forest a -> Forest a -> Forest a
skewMeld f ts ts' = unionUniq f (uniqify f ts) (uniqify f ts')
{-# INLINE skewMeld #-}

getMin :: (a -> a -> Bool) -> Forest a -> (Tree a, Forest a)
getMin _ (t `Cons` Nil) = (t, Nil)
getMin f (t `Cons` ts)
  | f (root t) (root t') = (t, ts)
  | otherwise            = (t', t `Cons` ts')
  where (t',ts') = getMin f ts
getMin _ Nil = error "Heap.getMin: empty forest"

splitForest :: Int -> Forest a -> Forest a -> Forest a -> (Forest a, Forest a, Forest a)
splitForest a b c d | a `seq` b `seq` c `seq` d `seq` False = undefined
splitForest 0 zs ts f = (zs, ts, f)
splitForest 1 zs ts (t `Cons` Nil) = (zs, t `Cons` ts, Nil)
splitForest 1 zs ts (t1 `Cons` t2 `Cons` f)
  -- rank t1 == 0
  | rank t2 == 0 = (t1 `Cons` zs, t2 `Cons` ts, f)
  | otherwise    = (zs, t1 `Cons` ts, t2 `Cons` f)
splitForest r zs ts (t1 `Cons` t2 `Cons` cf)
  -- r1 = r - 1 or r1 == 0
  | r1 == r2          = (zs, t1 `Cons` t2 `Cons` ts, cf)
  | r1 == 0           = splitForest (r-1) (t1 `Cons` zs) (t2 `Cons` ts) cf
  | otherwise         = splitForest (r-1) zs (t1 `Cons` ts) (t2 `Cons` cf)
  where
    r1 = rank t1
    r2 = rank t2
splitForest _ _ _ _ = error "Heap.splitForest: invalid arguments"

-- | Explicit priority/payload tuples. Useful to build a priority queue using
-- a 'Heap', since the payload is ignored in the Eq/Ord instances.
--
-- @
-- myHeap = 'fromList' ['Entry' 2 \"World", 'Entry' 1 \"Hello", 'Entry' 3 "!"]
--
-- ==> 'foldMap' 'payload' myHeap â‰¡ "HelloWorld!"
-- @
data Entry p a = Entry { priority :: p, payload :: a }
  deriving (Read,Show,Data,Typeable)

instance Functor (Entry p) where
  fmap f (Entry p a) = Entry p (f a)
  {-# INLINE fmap #-}

instance Foldable (Entry p) where
  foldMap f (Entry _ a) = f a
  {-# INLINE foldMap #-}

instance Traversable (Entry p) where
  traverse f (Entry p a) = Entry p `fmap` f a
  {-# INLINE traverse #-}

-- instance Comonad (Entry p) where
--   extract (Entry _ a) = a
--   extend f pa@(Entry p _) Entry p (f pa)

instance Eq p => Eq (Entry p a) where
  (==) = (==) `on` priority
  {-# INLINE (==) #-}

instance Ord p => Ord (Entry p a) where
  compare = compare `on` priority
  {-# INLINE compare #-}


{-data PairingHeap a = E | T a [PairingHeap a]-}

{-mergePairs [] = E-}
{-mergePairs [h] = h-}
{-mergePairs (h1 : h2 : hs) = merge (merge h1 h2) (mergePairs hs)-}

{-empty = E-}
{-isEmpty E = True-}
{-isEmpty _ = False-}

{-insert x h = merge (T x []) h-}

{-merge h E = h-}
{-merge E h = h-}
{-merge h1@(T x hs1) h2@(T y hs2) =-}
  {-if x > y then T x (h2 : hs1) else T y (h1 : hs2)-}

{-findMax E = error "empty heap"-}
{-findMax (T x hs) = x-}

{-deleteMax E = error "empty heap"-}
{-deleteMax (T x hs) = mergePairs hs-}

{-type Heap = PairingHeap-}

{-data PairingHeap a = E | T a (PairingHeap a) (PairingHeap a)-}

{-link (T x E m) a = T x a m-}
{-link (T x b m) a = T x E (merge (merge a b) m)-}

{-empty = E-}
{-insert x a = merge (T x E E) a-}

{-merge a E = a-}
{-merge E b = b-}
{-merge a@(T x _ _) b@(T y _ _) = if x >= y then link a b else link b a-}

{-findMax (T x a m) = x-}
{-deleteMax (T x a m) = merge a m-}

{-type Heap = LeftistHeap-}

{-data LeftistHeap a = E | T Int a (LeftistHeap a) (LeftistHeap a)-}
{-rank E = 0-}
{-rank (T r _ _ _) = r-}
{-makeT x a b = if rank a <= rank b then T (rank b + 1) x a b-}
                                  {-else T (rank a + 1) x b a-}
{-empty = E-}
{-insert x h = merge (T 1 x E E) h-}
{-merge h E = h-}
{-merge E h = h-}
{-merge h1@(T _ x a1 b1) h2@(T _ y a2 b2) =-}
  {-if x >= y then makeT x a1 (merge b1 h2)-}
            {-else makeT y a2 (merge h1 b2)-}
            
{-findMax (T _ x a b) = x-}
{-deleteMax (T _ x a b) = merge a b-}

{-type Heap = BinomialHeap-}
{-data Tree a = Node Int a [Tree a]-}
{-newtype BinomialHeap a = BH [Tree a]-}

{-rank (Node r x c) = r-}
{-root (Node r x c) = x-}

{-link t1@(Node r x1 c1) t2@(Node _ x2 c2) =-}
  {-if x1 >= x2 then Node (r+1) x1 (t2 : c1) else Node (r+1) x2 (t1 : c2)-}

{-insTree t [] = [t]-}
{-insTree t ts@(t' : ts') =-}
  {-if rank t < rank t' then t : ts else insTree (link t t') ts'-}

{-mrg ts1 [] = ts1-}
{-mrg [] ts2 = ts2-}
{-mrg ts1@(t1:ts1') ts2@(t2:ts2')-}
  {-| rank t1 < rank t2 = t1 : mrg ts1' ts2-}
  {-| rank t2 < rank t1 = t2 : mrg ts1 ts2'-}
  {-| otherwise = insTree (link t1 t2) (mrg ts1' ts2')-}

{-removeMaxTree [t] = (t, [])-}
{-removeMaxTree (t : ts) = if root t > root t' then (t, ts) else (t', t:ts')-}
  {-where (t', ts') = removeMaxTree ts-}

{-empty = BH []-}
{-insert x (BH ts) = BH (insTree (Node 0 x []) ts)-}
{-merge (BH ts1) (BH ts2) = BH (mrg ts1 ts2)-}
{-findMax (BH ts) = root t where (t, _) = removeMaxTree ts-}

{-deleteMax (BH ts) = BH (mrg (reverse ts1) ts2) where (Node _ x ts1, ts2) = removeMaxTree ts-}

{-data SplayHeap a = E | T (SplayHeap a) a (SplayHeap a)-}
{-partition pivot E = (E, E)-}
{-partition pivot t@(T a x b) =-}
  {-if x >= pivot then-}
    {-case b of-}
      {-E -> (t, E)-}
      {-T b1 y b2 ->-}
        {-if y >= pivot then-}
          {-let (small, big) = partition pivot b2-}
          {-in (T (T a x b) y small, big)-}
        {-else-}
          {-let (small, big) = partition pivot b1-}
          {-in (T a x small, T big y b2)-}
  {-else-}
    {-case a of-}
      {-E -> (E, t)-}
      {-T a1 y a2 ->-}
        {-if y >= pivot then-}
          {-let (small, big) = partition pivot a2-}
          {-in (T a1 y small, T big x b)-}
        {-else-}
          {-let (small, big) = partition pivot a1-}
          {-in (small, T big y (T a2 x b))-}

{-empty = E-}
{-insert x t = T a x b where (a, b) = partition x t-}

{-merge E t = t-}
{-merge (T a x b) t = T (merge ta a) x (merge tb b) where-}
  {-(ta, tb) = partition x t-}

{-findMax (T E x b) = x-}
{-findMax (T a x b) = findMax a-}

{-deleteMax (T E x b) = b-}
{-deleteMax (T (T E x b) y c) = T b y c-}
{-deleteMax (T (T a x b) y c) = T (deleteMax a) x (T b y c)-}

readInt b = B.foldl (\i c -> i * 10 + ord c - 48) 0 b
merge = union

findMin heap = fst $ fromJust $ viewMin heap

main = do
  inputs <- liftM (B.lines) B.getContents
  let [n, q] = map readInt $ B.words $ head inputs

  heaps <- newArray (1, n) empty :: IO (IOArray Int (Heap Int))
  
  mapM (\input -> do
    let
      argv = map readInt $ B.words input
      t = head argv
      i = argv !! 1
    heapi <- readArray heaps i
    case t of
      1 -> do
        print $ negate $ findMin heapi
      2 -> do
        writeArray heaps i (deleteMin heapi)
      3 -> do
        let c = negate $ argv !! 2
        writeArray heaps i (insert c heapi)
      4 -> do
        let j = argv !! 2
        heapj <- readArray heaps j
        writeArray heaps i (merge heapi heapj)
        writeArray heaps j empty
    ) $ tail inputs
