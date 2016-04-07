import Control.Monad
import Data.Maybe
import Data.List
import Text.Printf

main = do
    mn : inputs <- liftM lines getContents
    let
        [m, n] = map read $ words mn
        (puzzle', [targetBlock, targetPos]) = splitAt m inputs
        puzzle = map words puzzle'
        [r, c] = map read $ words targetPos :: [Int]
        (i, j) = fromJust $ find (\(i, j) -> any (\i -> puzzle !! i !! j == targetBlock) [0..m-1] && any (\j -> puzzle !! i !! j == targetBlock) [0..n-1]) [(i, j) | i <- [0..m-1], j <- [0..n-1]]
    print 1
    printf "%s (%d,%d) (%d,%d)\n" targetBlock i j r c
