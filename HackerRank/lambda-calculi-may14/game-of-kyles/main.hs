import Control.Monad
import qualified Data.Text as T
import Data.Bits
import Data.Array
import Data.List

main = do
  let
    dp = listArray (0, 300) $ map f [0..300] where
      f :: Int -> Int
      f 0 = 0
      f n = g 0 $ sort [xor (dp!x) (dp!y) | x <- [0..n-1], y <- [n-2-x, n-1-x], x <= y]
        where
          g k [] = k
          g k (x:xs) | k == x = g (k+1) xs
                     | k < x = k
                     | otherwise = g k xs
  t <- readLn
  replicateM_ t (do
    getLine
    s <- getLine
    if (0 ==) $ foldl1 xor $ map ((dp!) . T.length) $ T.split (=='X') $ T.pack s
      then putStrLn "LOSE"
      else putStrLn "WIN"
    )