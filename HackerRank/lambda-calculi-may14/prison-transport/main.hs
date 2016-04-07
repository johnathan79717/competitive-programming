import Control.Monad
import Data.Array.IO

main = do
  n <- readLn
  m <- readLn
  adj <- newArray (1, n) [] :: IO (IOArray Int [Int])
  replicateM_ m (do
    [p, q] <- liftM (map read . words) getLine
    adjp <- readArray adj p
    writeArray adj p (q : adjp)
    adjq <- readArray adj q
    writeArray adj q (p : adjq)
    )
  visited <- newArray (1, n) False :: IO (IOArray Int Bool)
  let
    dfs k = do
      v <- readArray visited k
      if v then return 0 else (do
        writeArray visited k True
        xs <- readArray adj k
        liftM ((1+).sum) $ mapM dfs xs
        )
  ans <- mapM dfs [1..n]
  print $ sum $ map (ceiling.sqrt) ans