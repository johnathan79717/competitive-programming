start = play (zip (reverse [1..5]) [1..5])

play board = do
  if all (\(x, i) -> x == 0) board then
    putStrLn "You won!"
  else
    do
      mapM_ printBoard board
      putStr "Which row to remove? "
      r <- getLine
      putStr "How many to remove? "
      n <- getLine
      play (map (\ (x, i) -> if i /= (read r :: Int) then (x, i) else (x - (read n :: Int), i))  board)

printBoard (x, i) = do
  putStr (show i)
  putChar ':'
  mapM_ putStr (replicate x " *")
  putStrLn ""