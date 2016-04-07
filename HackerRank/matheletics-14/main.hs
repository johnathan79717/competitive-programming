data Z = Z Integer deriving Show
data M = M Z Z Z Z deriving Show

m = 1000000007

instance Num Z where
  Z a + Z b = Z ((a + b) `mod` m)
  Z a - Z b = Z ((a - b + m) `mod` m)
  Z a * Z b = Z ((a * b) `mod` m)
  fromInteger i = Z i

instance Num M where
  M a11 a12 a21 a22 + M b11 b12 b21 b22 = 
    M (a11 + b11) (a12 + b12) (a21 + b21) (a22 + b22)
  M a11 a12 a21 a22 * M b11 b12 b21 b22 = 
    M (a11 * b11 + a12 * b21) (a11 * b12 + a12 * b22) (a21 * b11 + a22 * b21) (a21 * b12 + a22 * b22)
  fromInteger = error ""

pow a 1 = a
pow a n = let x = pow a (n `div` 2)
  in if n `mod` 2 == 0 then x * x else x * x * a

a = M 0 1 1 1

ans n = let M x _ _ y = a ^ n in (Z 2) ^ n - x - y