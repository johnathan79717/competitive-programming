import Control.Monad

main = do
  getLine
  a <- liftM (map read . words) getLine
  getLine
  b <- liftM (map read . words) getLine
  print $ gcd (product a) (product b) `mod` 1000000007
