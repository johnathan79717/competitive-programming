import Control.Monad

data Matrix = Matrix Integer Integer Integer Integer deriving (Eq, Show)

matmul :: Matrix -> Matrix -> Matrix
matmul (Matrix a11 a12 a21 a22) (Matrix b11 b12 b21 b22) = Matrix c11 c12 c21 c22
  where c11 = a11 * b11 + a12 * b21
        c12 = a11 * b12 + a12 * b22
        c21 = a21 * b11 + a22 * b21
        c22 = a21 * b12 + a22 * b22

type Vector = (Integer, Integer)

vecmul :: Matrix -> Vector -> Vector
vecmul (Matrix a11 a12 a21 a22) (x, y) = (a11 * x + a12 * y, a21 * x + a22 * y)

matpow :: Matrix -> Integer -> Matrix
matpow _ 0 = Matrix 1 0 0 1
matpow m n
  | n `mod` 2 == 0 = let half = matpow m $ quot n 2 in half `matmul` half
  | otherwise      = matpow m (n - 1) `matmul` m

main = do
  t <- liftM read getLine
  replicateM_ t $ do
    [n, k] <- liftM (map read . words) getLine
    let matrix = matpow (Matrix 0 k 1 (k-1)) n
    print $ (fst $ vecmul matrix (1, 0)) `mod` 1000000007