import Control.Monad
import Data.List
import Data.Array

lower_bound acc s = while 0 . (+1) . snd . bounds $ acc where
    while lb ub
        | ub - lb <= 1 = ub
        | otherwise = let m = (lb + ub) `div` 2 in
            if acc ! m >= s then while lb m else while m ub

main = do
    n <- readLn
    a <- liftM (map read . words) getLine
    let acc = listArray (1,length a) . scanl1 (+) . reverse $ sort a
    t <- readLn :: IO Int
    ss <- liftM (map read . lines) getContents
    forM_ ss (\s -> do
        let ans = lower_bound acc s
        print $ if ans > n then -1 else ans
        )