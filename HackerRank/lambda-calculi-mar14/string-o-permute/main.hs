import Control.Monad

solve [] = []
solve (a:b:cs) = b : a : solve cs

main = do
  t <- liftM read getLine
  replicateM_ t (do
    str <- getLine
    putStrLn $ solve str
    )