import Control.Monad
import Data.Array

type Data = [(Int, Int)]
data Node = Leaf Data | Internal Data Node Node deriving (Show)

power n p = if mod n p == 0 then 1 + power (div n p) p else 0

f n = reverse $ snd $ foldl try (n, []) [2..97] where
    try (x, ans) p = let d = power x p in if d == 0 then (x, ans) else (div x (p^d), (p, d):ans)

value (Leaf d) = d
value (Internal d _ _) = d

merge [] a = a
merge a [] = a
merge a1@(pr1@(p1,n1):s1) a2@(pr2@(p2,n2):s2)
    | p1 < p2 = pr1:merge s1 a2
    | p1 > p2 = pr2:merge a1 s2
    | True = (p1, max n1 n2):merge s1 s2

newtype Z = Z Int

instance Show Z where
    show (Z i) = show i

mod' = 1000000007
instance Num Z where
    Z a + Z b = Z $ if c < mod' then c else c - mod' where c = a + b
    Z a - Z b = Z $ if c >= 0 then c else c + mod' where c = a - b
    Z a * Z b = Z $ a * b `mod` mod'
    abs = undefined
    signum = undefined
    fromInteger = undefined

toAns [] = Z 1
toAns ((p,n):tl) = (Z p)^n * toAns tl

mul [] v = v
mul v [] = v
mul v1@(pr1@(p1,n1):t1) v2@(pr2@(p2,n2):t2) = if p1 < p2 then
    pr1 : mul t1 v2 else if p1 > p2 then pr2 : mul v1 t2 else
        (p1,n1+n2) : mul t1 t2


main = do
    (nStr:aStr:kStr:queries) <- liftM lines getContents
    let 
        n = read nStr :: Int
        a = listArray (0, n-1) $ map read $ words aStr :: Array Int Int
        mp = listArray (1, 100) [f x | x <- [1..100]]
        init l r = if r - l == 1 then Leaf (mp ! (a ! l)) else let
            m = div (l+r) 2
            left = init l m
            right = init m r
            in Internal (merge (value left) (value right)) left right
        tree = init 0 n

    -- print root
    let (ans, _) = foldl (\(ans, root) input -> do
        let 
            query a b = query a (b+1) root 0 n where
                query a b node l r = if r <= a || b <= l then [] else
                    if a <= l && r <= b then value node else
                        let
                            m = div (l+r) 2
                            Internal _ chl chr = node
                            vl = query a b chl l m
                            vr = query a b chr m r
                            in merge vl vr
            update i v = update i v root 0 n where
                update _ v (Leaf d) _ _ | otherwise = Leaf $ mul d v
                update i v (Internal _ left right) l r = let
                    m = div (l+r) 2
                    in if i < m then let left' = update i v left l m in
                        Internal (merge (value left') (value right)) left' right
                        else let right' = update i v right m r in
                            Internal (merge (value left) (value right')) left right'
        let typ:i1:i2:_ = words input
        case typ of
            'Q':_ -> let
                l = read i1 :: Int
                r = read i2 :: Int
                -- in return $ show $ toAns $ query l r
                in (toAns (query l r) : ans, root)
            otherwise -> let
                idx = read i1 :: Int
                val = read i2 :: Int
                in (ans, update idx $ mp ! val)
        ) ([], tree) queries
    putStr $ unlines $ reverse $ map show ans
    -- putStr $ unlines $ filter (\x -> not $ null x) ans