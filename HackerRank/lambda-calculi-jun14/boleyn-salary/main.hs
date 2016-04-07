import Control.Monad
import Data.Array.IO
import Data.Array
import qualified Data.DList as D
import qualified Data.IntMap as M
import Data.List

main = do
  let readWords = liftM (map read . words) getLine
  [n, q] <- readWords
  up <- replicateM (n-1) readWords
  s' <- readWords
  vk <- replicateM q readWords
  children <- newArray (1, n) [] :: IO (IOArray Int [Int])
  forM_ up (\[u, p] -> do
    pchildren <- readArray children p
    writeArray children p $ u : pchildren
    )
  let s = listArray (1, n) s'
  start <- newArray (1, n) 0 :: IO (IOArray Int Int)
  end <- newArray (1, n) 0 :: IO (IOArray Int Int)
  let
    recordStartEnd k v = do
      writeArray start v (k+1)
      vs <- readArray children v
      ans <- foldM recordStartEnd (k+1) vs
      writeArray end v ans
      return ans
  recordStartEnd 0 1
  segtree <- newArray (0, 100000) [] :: IO (IOArray Int [Int])
  let
    buildDfsOrder v = do
      vs <- readArray children v
      cs <- mapM buildDfsOrder vs
      return $ (s ! v) `D.cons` D.concat cs
  dfsOrder <- liftM (listArray (0, n-1) . D.toList) $ buildDfsOrder 1
  let
    initialize k l r
      | r - l == 1 = writeArray segtree k [dfsOrder ! l]
      | otherwise = do
        let chl = k * 2 + 1
        let chr = k * 2 + 2
        let m = div (l + r) 2
        initialize chl l m
        initialize chr m r
        vl <- readArray segtree chl
        vr <- readArray segtree chr
        let
          merge as@(a:as') bs@(b:bs')
            | a > b = b:merge as  bs'
            | otherwise       = a:merge as' bs
          merge [] bs         = bs
          merge as []         = as
        writeArray segtree k $ merge vl vr
  initialize 0 0 n
  segtree <- mapArray (\l -> listArray (1, length l) l) segtree
  let
    query val a b k l r
      | r <= a || b <= l = return 0
      | a <= l && r <= b = do
        xs <- readArray segtree k
        let
          search lb ub
            | ub - lb <= 1 = lb
            | otherwise =
              let m = div (lb + ub) 2
              in if xs ! m <= val then search m ub else search lb m
        return $ search 0 (snd (bounds xs)+1)
      | otherwise = do
        let m = div (l + r) 2
        vl <- query val a b (k*2+1) l m
        vr <- query val a b (k*2+2) m r
        return $ vl + vr
  let ss = listArray (1, n) $ sort s'
  let mp = M.fromList $ zip s' [1..]
  foldM (\d [v', k] -> do
    let v = v' + d
    a <- readArray start v
    b <- readArray end v
    let
      search lb ub
        | ub - lb <= 1 = return ub
        | otherwise = do
          let mid = div (lb + ub) 2
          cnt <- query (ss ! mid) a b 0 0 n
          if cnt < k then search mid ub else search lb mid
    val <- search 0 n
    let Just ans = M.lookup (ss ! val) mp
    print ans
    return ans
    ) 0 vk