import Control.Monad
import Data.Array

layer m n i j = minimum [i, j, m+1-i, n+1-j]
number m n i j 
  | j == l          = i - l
  | i == m + 1 - l  = j - l + number m n (m+1-l) l
  | j == n + 1 - l  = (m + 1 - l) - i + number m n (m+1-l) (n+1-l)
  | i == l          = (n + 1 - l) - j + number m n l (n+1-l)
    where l = layer m n i j
position m n l num
  | num <= number m n (m+1-l) l = (l + num, l)
  | num <= number m n (m+1-l) (n+1-l) = (m+1-l, num - number m n (m+1-l) l + l)
  | num <= number m n l (n+1-l) = (m + 1 - l + number m n (m+1-l) (n+1-l) - num, n+1-l)
  | otherwise = (l, n + 1 - l + number m n l (n+1-l) - num)

main = do
  [m, n, r] <- liftM (map read . words) getLine
  a <- liftM (listArray ((1, 1), (m, n)) . concat) $
    replicateM m $ liftM words getLine
  putStr $ unlines $ map (unwords) [[ a ! pos | j <- [1..n],
               let l = layer m n i j,
               let num = number m n i j,
               let md = number m n l (l+1) + 1,
               let pos = position m n l $ (num - r) `mod` md
               ] | i <- [1..m]]
