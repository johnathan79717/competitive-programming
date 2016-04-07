import Control.Monad
import Data.Array
import Data.List
import Data.Maybe

solve n pass loginAttempt = dp ! n where
  suffixes = listArray (0, n) . reverse . tails $ loginAttempt
  n = length loginAttempt
  dp = listArray (0, n) (Just [] : map f [1..n])
  f i = find (not . null) $ map g pass where
    g p = if i >= lp && not (isNothing dpilp) && isPrefixOf p si then p : (fromJust dpilp) else [] where
      lp = length p
      dpilp = dp ! (i - lp)
    si = suffixes ! i

main = do
  t <- readLn :: IO Int
  forM_ [1..t] (\_ -> do
    n <- readLn :: IO Int
    pass <- liftM words getLine
    loginAttempt <- getLine
    putStrLn $ case solve n pass loginAttempt of Nothing -> "WRONG PASSWORD"; Just ps -> unwords ps
    )
