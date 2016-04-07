import Control.Monad

main = do
  xs <- replicateM 100 getLine
  print $ sum $ map read xs