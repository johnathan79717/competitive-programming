import Control.Monad
import Data.List
import Data.Ord
import Data.Maybe
import Data.IntMap (IntMap)
import qualified Data.IntMap as I

data Building = B {v::Int, h::Int, i::Int} deriving Show

main = do
    _ : hStr : vStr : qStr <- liftM lines getContents
    let
        hs = map read $ words hStr :: [Int]
        vs = map read $ words vStr :: [Int]
        check (b1:bs1@(b2:bs2))
            | v b1 == v b2 = check bs1
            | otherwise =  b1 : (check2 (check bs1)) where
                check2 b@(b2:bs2@(b3:bs3))
                    | (h b1 - h b2) * (v b3 - v b2) > (h b2 - h b3) * (v b2 - v b1) = check2 bs2
                    | otherwise = b
                check2 b = b
        check b = b
        vh = check $ sortBy (\(B v1 h1 i1) (B v2 h2 i2) -> compare (v1, h1, i1) (v2, h2, i2)) $ zipWith3 B vs hs [1..]
        removeDup (x:xs) = x : removeDup (dropWhile (x==) xs)
        removeDup [] = []
        queries = map read qStr
        queriesSorted = removeDup $ sort queries
        solve [] _ ans = ans
        solve (q:qs) b@[B _ _ i1] ans = solve qs b (I.insert q i1 ans)
        solve qq@(q:qs) b@((B v1 h1 _):bs1@((B v2 h2 _):_)) ans
            | y1 < y2 = solve qq bs1 ans
            | otherwise = let (bb1, bb2) = span (\(B v' h' _) -> y1 == v' * q + h') b
                in solve qs (last bb1 : bb2) (I.insert q (maximum $ map i bb1) ans)
            where
                y1 = h1 + v1 * q
                y2 = h2 + v2 * q
        ans = solve queriesSorted vh I.empty
    putStr $ unlines $ map (\q -> show $ fromJust $ I.lookup q ans) queries