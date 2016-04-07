import Control.Monad
import Data.List
import Data.Maybe
import Data.Array

better Nothing b = b
better a Nothing = a
better (Just a) (Just b) = if small a b == LT then (Just a) else (Just b)
  --where
small [] [] = EQ
small [] b = LT
small a [] = GT
small (a:as) (b:bs) = let c = small as bs in
  if c /= EQ then c else compare a b

dp 1 0 _ = Just []
dp _ 0 _ = Nothing
dp n k a = let ak = a ! k in
  if mod n ak /= 0 then dp n (k-1) a
    else let ans = dp (div n ak) k a in
      if isNothing ans then dp n (k-1) a
        else better (dp n (k-1) a) (Just (ak : fromJust ans))

main = do
  [n, k] <- liftM (map read . words) getLine
  a' <- liftM (sort . map read . words) getLine
  let a = listArray (1, k) a'
  case dp n k a of
    Nothing -> putStrLn "-1"
    Just xs -> putStrLn $ unwords $ map show $ reverse $ scanr (*) 1 xs