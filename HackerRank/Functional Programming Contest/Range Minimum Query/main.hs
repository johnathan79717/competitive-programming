import Control.Monad
import Data.Array.IArray

data Node = Leaf {value :: Int} | Tree {left :: Node, right :: Node, value :: Int} deriving Show

initialize l r f
  | r - l == 1 = Leaf (f l)
  | otherwise  = Tree chl chr $ min (value chl) (value chr) where
    m = div (l + r) 2
    chl = initialize l m f
    chr = initialize m r f

query a b l r node
  | r <= a || b <= l = 10001
  | a <= l && r <= b = value node
  | otherwise = min vl vr where
    m = div (l+r) 2
    vl = query a b l m $ left node
    vr = query a b m r $ right node

--tree = initialize 0 10 f
--arr = listArray (0, 9) [10, 20, 30, 40, 11, 22, 33, 44, 15, 5] :: (Array Int Int)
--f = (!) arr

main = do
  [n, m] <- liftM (map read . words) getLine
  arr <- liftM (listArray (0, n-1) . map read . words) getLine :: IO (Array Int Int)
  let segment_tree = initialize 0 n $ (!) arr
  --print segment_tree
  replicateM_ m (do
    [l, r] <- liftM (map read . words) getLine
    print $ query l (r+1) 0 n segment_tree
    )
