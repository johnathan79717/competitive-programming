import Control.Monad

solve :: Integer -> Integer -> (Integer, Integer)
solve 0 k = (1, 0)
solve n k = let (messi, teammate) = solve (n-1) k
            in (k * teammate, messi + (k-1) * teammate)

main = do
  t <- liftM read getLine
  replicateM_ t $ do
    [n, k] <- liftM (map read . words) getLine
    print $ (fst $ solve n k) `mod` 1000000007