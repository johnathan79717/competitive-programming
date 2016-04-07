solveRPN :: (Num a, Read a) => String -> a
solveRPN = head . foldl foldingFunction [] . words
  where foldingFunction (x:y:xs) "*" = (x*y):xs
        foldingFunction (x:y:xs) "+" = (x+y):xs
        foldingFunction (x:y:xs) "-" = (y-x):xs
        foldingFunction xs numberString = read numberString:xs