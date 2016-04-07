import Control.Monad
import Prelude hiding (readList)
import Data.List
import Debug.Trace

readLine = liftM read getLine
readList = liftM (map read . words) getLine

cross (x1, y1) (x2, y2) (x3, y3) (x4, y4) = (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4)

{-convex k t q p | traceShow (k, t, q, p) False = undefined-}
convex _ _ qs [] = qs
convex k t (q1:q2:qs) (p:ps) | k > t && cross q1 q2 p q1 < 0 = convex (k-1) t (q2:qs) (p:ps)
convex k t qs (p:ps) = convex (k+1) t (p:qs) ps

main = do
    n <- readLine
    (p:ps) <- liftM sort $ replicateM n $ do
        [x, y] <- readList :: IO [Int]
        return (x, y)
    
    let qs1 = convex 1 1 [p] ps
    let k = length qs1
    let qs2 = tail $ convex k k qs1 $ tail $ reverse $ p : ps
    {-print qs1-}
    {-print qs2-}
    let l = length qs2
    putStrLn $ if l < 3 || n == l then "NO" else "YES"
