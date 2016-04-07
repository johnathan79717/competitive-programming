import Control.Monad
import Data.Bits
import Data.Array
import Debug.Trace

main = do
    (n':a':t':inputs) <- liftM lines getContents
    -- n <- readLn :: IO Int
    let n = read n'
    -- a <- liftM (listArray (0, n-1) . map read . words) getLine :: IO (Array Int Int)
    let a = listArray (0, n-1) . map read . words $ a' :: Array Int Int
    let logTable = listArray (0, n) [ if i < 2 then 0 else 1 + logTable ! (shiftR i 1) | i <- [0..n]]
    -- print logTable
    let st = listArray ((0, 0), (15, n-1)) [ if k == 0 then (a!i, a!i) else if i + shift 1 k > n then (0, 0) else let
            (x1, x2) = st ! (k-1, i)
            (y1, y2) = st ! (k-1, i + shift 1 (k-1))
            in (min x1 y1, max x2 y2) | k <- [0..15], i <- [0..n-1]]
    let
        rmq i j = let
            k = logTable ! (j - i + 1)
            (x1, x2) = st ! (k, i)
            (y1, y2) = st ! (k, j - shiftL 1 k + 1)
            in (min x1 y1, max x2 y2)
    -- t <- readLn :: IO Int
    -- let t = read t'
    -- liftM print getContents
    -- ans <- replicateM t $ do
    ans <- forM inputs $ \input -> do
        -- [d, m] <- liftM (map read . words) getLine :: IO [Int]
        let [d, m] = map read . words $ input
        let lb = a ! d
        let ub = m + lb
        let
            rightSearch l r = if r - l <= 1 then l else let
                m = div (l+r) 2
                (min, max) = rmq d m
                in if min >= lb && max <= ub then rightSearch m r else rightSearch l m
            leftSearch l r = if r - l <= 1 then r else let
                m = div (l+r) 2
                (min, max) = rmq m d
                in if min >= lb && max <= ub then leftSearch l m else leftSearch m r
        -- print $ rmq d m
        let l = leftSearch (-1) d
        let r = rightSearch d n
        -- print (leftSearch (-1) d, rightSearch d n)
        -- print (r - l + 1)
        return (r - l + 1)
    putStr $ unlines $ map show ans