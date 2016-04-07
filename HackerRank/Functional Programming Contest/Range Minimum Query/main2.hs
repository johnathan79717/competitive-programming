import Control.Monad
import Data.Array.IArray
import Data.Array.IO

initialize arr dat k l r
  | r - l == 1 = writeArray dat k $ arr ! l
  | otherwise  = (do
    let chl = k * 2 + 1
    let chr = k * 2 + 2
    let m = div (l + r) 2
    initialize arr dat chl l m
    initialize arr dat chr m r
    vl <- readArray dat chl
    vr <- readArray dat chr
    writeArray dat k $ min vl vr
    )

query dat a b k l r
  | r <= a || b <= l = return inf
  | a <= l && r <= b = readArray dat k
  | otherwise = (do
    let m = div (l + r) 2
    vl <- query dat a b (k*2+1) l m
    vr <- query dat a b (k*2+2) m r
    return $ min vl vr
    )

inf = 1000000000

main = do
  [n, m] <- liftM (map read . words) getLine
  arr <- liftM (listArray (0, n-1) . map read . words) getLine :: IO (Array Int Int)
  dat <- newArray (0, 262143) inf :: IO (IOArray Int Int)
  initialize arr dat 0 0 n
  replicateM_ m (do
    [l, r] <- liftM (map read . words) getLine
    result <- query dat l (r+1) 0 0 n
    print result
    )
