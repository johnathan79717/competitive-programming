import Control.Monad
import Data.Array
import Data.Set (Set)
import qualified Data.Set as S

data Node = Internal (Set Int) Node Node | Leaf (Set Int) deriving Show

getList (Leaf x) = x
getList (Internal x _ _) = x

main = do
    inputs <- liftM lines getContents
    let
        (nm:input1) = inputs
        [n, m] = map read $ words nm
        (as:input2) = input1
        (bs:input3) = input2
        aNode = build a 1 (n+1) where
            a = listArray (1, n) $ map read $ words as :: Array Int Int
        bNode = build b 1 (m+1) where
            b = listArray (1, m) $ map read $ words bs :: Array Int Int
        build x l r
            | r - l == 1 = Leaf $ S.singleton $ x ! l
            | otherwise  = let
                mid = div (l + r) 2
                lNode = build x l mid
                rNode = build x mid r
                list = S.union (getList lNode) (getList rNode)
                in Internal list lNode rNode
        (qIn : input4) = input3
        query = map (map read . words) input4 :: [[Int]]
        rank node l r i = binary_search 1 1000000000 where
            binary_search lb ub
                | ub - lb = 1 = 
                | otherwise   = let
                    x = div (ub + lb) 2
                    
    print aNode
    print bNode
    forM_ query $ \[x, y, z, w] -> do
        let l = y - x + 1 + w - z + 1
        let ra = rank aNode x y (div l 2)
        print (x, y, z, w)