import Control.Applicative
import Control.Monad

main = do
  [n, t, m] <- map read <$> words <$> getLine
  -- read m lines of input
  map ( list2Bus . map read . words) <$> replicateM m getLine

data Bus = Bus { startStation   :: Int
               , arriveStation  :: Int
               , startTime      :: Int
               , arriveTime     :: Int
               } deriving Show

list2Bus :: [Int] -> Bus
list2Bus [u, v, s, e] = Bus u v s e