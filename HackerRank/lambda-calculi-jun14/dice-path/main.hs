import Control.Monad
import Data.Array

ori 1 = (1, 2, 4)
ori 2 = (1, 4, 5)
ori 3 = (1, 5, 3)
ori 4 = (1, 3, 2)
ori 5 = (2, 1, 3)
ori 6 = (2, 3, 6)
ori 7 = (2, 6, 4)
ori 8 = (2, 4, 1)
ori 9 = (3, 2, 1)
ori 10 = (3, 1, 5)
ori 11 = (3, 5, 6)
ori 12 = (3, 6, 2)
ori 13 = (4, 1, 2)
ori 14 = (4, 2, 6)
ori 15 = (4, 6, 5)
ori 16 = (4, 5, 1)
ori 17 = (5, 1, 4)
ori 18 = (5, 4, 6)
ori 19 = (5, 6, 3)
ori 20 = (5, 3, 1)
ori 21 = (6, 2, 3)
ori 22 = (6, 3, 5)
ori 23 = (6, 5, 4)
ori 24 = (6, 4, 2)

inv (1, 2, 4) =  1
inv (1, 4, 5) =  2
inv (1, 5, 3) =  3
inv (1, 3, 2) =  4
inv (2, 1, 3) =  5
inv (2, 3, 6) =  6
inv (2, 6, 4) =  7
inv (2, 4, 1) =  8
inv (3, 2, 1) =  9
inv (3, 1, 5) =  10
inv (3, 5, 6) =  11
inv (3, 6, 2) =  12
inv (4, 1, 2) =  13
inv (4, 2, 6) =  14
inv (4, 6, 5) =  15
inv (4, 5, 1) =  16
inv (5, 1, 4) =  17
inv (5, 4, 6) =  18
inv (5, 6, 3) =  19
inv (5, 3, 1) =  20
inv (6, 2, 3) =  21
inv (6, 3, 5) =  22
inv (6, 5, 4) =  23
inv (6, 4, 2) =  24

up = inv . r . ori where r (a, b, c) = (b, 7-a, c)
left = inv . d . ori where d (a, b, c) = (c, b, 7-a)
val r = (r + 3) `div` 4

dp = array ((1, 1, 1), (60, 60, 24)) $ map f [(m, n, r) | m <- [1..60], n <- [1..60], r <- [1..24]] where
  f (1, 1, 1) = ((1, 1, 1), 1)
  f (1, 1, r) = ((1, 1, r), 0)
  f (1, n, r) = ((1, n, r), if ans > 0 then val r + ans else 0) where
    ans = dp ! (1, n-1, left r)
  f (m, 1, r) = ((m, 1, r), if ans > 0 then val r + ans else 0) where
    ans = dp ! (m-1, 1, up r)
  f (m, n, r) = ((m, n, r), max a b) where
    a = if ans > 0 then val r + ans else 0 where
      ans = dp ! (m, n-1, left r)
    b = if ans > 0 then val r + ans else 0 where
      ans = dp ! (m-1, n, up r)

main = do
  t <- readLn
  replicateM_ t (do
    [m, n] <- liftM (map read . words) getLine
    print $ maximum $ map (\i -> dp ! (m, n, i)) [1..24]
    )