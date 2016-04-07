import Data.Char

fact 0 = 1
fact n = n * fact (n-1)

sumOfFact :: Int -> Int
sumOfFact = sum . map (fact . digitToInt) . show

chain n = case n of
          145       -> 1
          169       -> 3
          363601    -> 3
          1454      -> 3
          871       -> 2
          45361     -> 2
          872       -> 2
          45362     -> 2
          otherwise -> 1 + chain (sumOfFact n)
