newtype LastTen = LastTen Integer deriving Show

m = 10000000000

instance Num LastTen where
  LastTen a + LastTen b = LastTen $ (a + b) `mod` m
  LastTen a - LastTen b = LastTen $ (a - b) `mod` m
  LastTen a * LastTen b = LastTen $ (a * b) `mod` m

  