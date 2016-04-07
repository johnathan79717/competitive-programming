import Control.Monad

num_divisors g = sum [if d^2 == g then 1 else 2 | d <- [1..floor $ sqrt $ fromIntegral g], mod g d == 0]

main = do
  t <- liftM read getLine
  replicateM_ t (do
    [l, m] <- liftM (map read . words) getLine
    print $ num_divisors $ gcd l m
    )