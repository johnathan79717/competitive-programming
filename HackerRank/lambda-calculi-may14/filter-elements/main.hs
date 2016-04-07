import Control.Monad
import qualified Data.IntMap as M
import Data.IntMap hiding (map, filter, null)

main = do
    t <- readLn
    replicateM_ t (do
        s1 <- getLine
        let [n, k] = map read $ words s1 :: [Int]
        s2 <- getLine
        let a = map read $ words s2 :: [Int]
        let m = fromListWith (+) $ zip a $ repeat 1
        let o = fromListWith (flip const) $ zip a [0..]
        --print o
        let ans = filter (\(x, c) -> o ! x == c && m ! x >= k) $ zip a [0..]
        if null ans then print (-1) else putStrLn $ unwords $ map (show . fst) ans
        )