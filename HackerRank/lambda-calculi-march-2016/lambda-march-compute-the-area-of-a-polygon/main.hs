import Control.Monad
import Prelude hiding (readList)

readLine = liftM read getLine
readList = liftM (map read . words) getLine

cross (x1, y1) (x2, y2) = x1 * y2 - x2 * y1

area (p1 : p2 : ps) = cross p1 p2 / 2 + area (p2 : ps)
area _ = 0

main = do
    n <- readLine
    ps <- replicateM n $ do
        [x, y] <- readList
        return (x, y)

    print $ abs $ area $ last ps : ps
