-- Enter your code here. Read input from STDIN. Print output to STDOUT
import Control.Monad
import Data.Char
import Data.Array
main = do
  n <- readLn :: IO Int
  accounts' <- liftM (filter (/=' ')) getLine
  let len = length accounts'
  let accounts = listArray (1, len) accounts'
  --print len
  --print accounts
  let
    g '0' = 10
    g n = digitToInt n
  let
    dp = array ((1, 1, 1), (len, 10, 10)) [ ((i, j, k), f i j k)
                                        | i <- [1..len]
                                        , j <- [1..10]
                                        , k <- [1..10]]
    f 1 j k = min (abs (c - j)) (abs (c - k)) where c = g (accounts ! 1)
    f i j k = min ((dp ! (i - 1, c, k)) + abs (c - j)) 
                    ((dp ! (i - 1, j, c)) + abs (c - k))
                    where c = g (accounts ! i)
    --f _ _ _ _ = 0
  --print dp
  print $ (len+) $ minimum $ [dp ! (len, i, j) | i <- [1..10], j <- [1..10]]
