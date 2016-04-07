import Control.Monad
import Control.Applicative

c _ 0 = 1
c n k = c (n-1) (k-1) * n `div` k

solve 0 _ _ = ""
solve n k m
  | m > c n k       = "-1"
  | m <= c (n-1) k  = '0' : solve (n-1) k m
  | otherwise       = '1' : solve (n-1) (k-1) (m - c (n-1) k)

main = do
  t <- read <$> getLine
  replicateM_ t ( do
    [n, k, m] <- map read <$> words <$> getLine
    putStrLn $ solve n k m
    )