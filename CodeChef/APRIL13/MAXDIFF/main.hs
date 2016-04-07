import Control.Monad
import Control.Applicative
import Data.List

main = do
  t <- read <$> getLine :: IO Int
  replicateM_ t ( do
    [n, k] <- map read <$> words <$> getLine :: IO [Int]
    w <- map read <$> words <$> getLine :: IO [Int]
    print $ maximum_weight_difference k n w
    )

maximum_weight_difference :: Int -> Int -> [Int] -> Int
maximum_weight_difference k n w = sum chef - sum son
  where sorted_items  = sort w
        sons_items    = min k (n - k)
        (son, chef)   = splitAt sons_items sorted_items