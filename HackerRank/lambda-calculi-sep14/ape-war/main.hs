import Control.Monad
import Data.Array
import Data.Bits
import qualified Data.Set as S
main = do
  [n, m] <- liftM (map read . words) getLine :: IO [Int]
  p <- liftM (map read . words) getLine :: IO [Int]
  let
    parent = listArray ((0, 1), (15, n)) $
      (0:p) ++ [f k v | k <- [1..15], v <- [1..n]] where
      f k v = let p1 = parent ! (k-1, v)
              in if p1 == 0 then 0 else parent ! (k-1, p1)
  let depth = listArray (1, n) $ (0::Int) : [1 + depth ! (parent ! (0, v)) | v <- [2..n]]
  let
    lca u v | depth ! u > depth ! v = lca v u
    lca u v | otherwise =
      let v' = foldl (\v k -> if testBit (depth ! v - depth ! u) k then parent ! (k, v) else v) v [0..15]
      in if u == v' then u else
        let (u', _) = foldl (\(u, v) k -> if parent ! (k, u) /= parent ! (k, v) then (parent ! (k, u), parent ! (k, v)) else (u, v) ) (u, v') [15, 14..0]
        in parent ! (0, u')
  --print parent
  --print depth
  let path = listArray (0, n) $ S.empty : [S.insert v $ path ! (parent ! (0, v)) | v <- [1..n]]
  --print path
  c <- liftM lines getContents
  forM_ c $ \c -> do
    let [x, y, l, r] = map read $ words c
    let
      countRange s = S.size s'' where
        (_, s') = S.split (l-1) $ path ! s
        (s'', _) = S.split (r+1) s'
    let a = lca x y
    print a
    --print $ countRange x + countRange y - countRange a - countRange (parent ! (0, a))
