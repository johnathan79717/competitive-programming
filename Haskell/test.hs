double x = x + x
quadruple = double.double

ab :: Int -> Int
ab n = if n >= 0 then n else -n

ad = \x -> (\y -> x + y)

len :: [Int] -> Int
len [] = 0
len (_:xs) = len xs + 1

inS :: Int -> Bool
inS n | n < 0 = False
      | n == 0 = True
      | otherwise = inS (n - 3)

inS2 0 = True
inS2 1 = False
inS2 2 = False
inS2 (n+3) = inS n

nth :: [a] -> Int -> a
nth (x:_) 0 = x
nth (_:xs) n = nth xs (n-1)

nth2 :: [a] -> Int -> a
nth2 (x:xs) n | n == 0 = x
             | otherwise = nth2 xs (n-1)


