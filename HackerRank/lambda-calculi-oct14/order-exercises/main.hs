import Data.List
import Control.Monad
import Data.Array
import Data.Array.IO

main = do
  [n, k'] <- liftM (map read . words) getLine :: IO [Int]
  a <- liftM (map read . words) getLine :: IO [Int]
  stack <- newArray (1, n) (0, 0, 0, 0) :: IO (IOArray Int (Int, Int, Int, Int))
  let
    p = do
      --ans <- getElems stack
      --print ans
      return ()
    f [] k _ _ = return k
    f (a:as) k total i
      | a < 0 = f as k r (i+1)
      | k == 0 = do
        writeArray stack (k+1) (i, l, r, 0)
        p
        f as (k+1) r (i+1)
      | otherwise = do
        let
          getLess 0 = return 0
          getLess k = do
            (_, lk, _, pk) <- readArray stack k
            if lk <= l then return k else getLess pk
        j <- getLess k
        --print j
        writeArray stack (k+1) (i, l, r, j)
        p
        let
          consider k = do
            (ik, lk, rk, j) <- readArray stack k
            if j == 0 then return k else do
              (ij, lj, rj, pj) <- readArray stack j
              if rj >= rk then return k else do
                writeArray stack j (ij, lj, rk, pj)
                p
                consider j
        k <- consider (k+1)
        f as k r (i+1)
      where 
        l = total
        r = total + a
  k <- f a 0 0 1
  ans <- liftM (map (negate . fst) . take k' . sort . map (\(i, l, r, _) -> (l-r, i)) . take k) $ getElems stack
  forM_ ans print
  return ()