import Control.Monad

distance (x1, y1) (x2, y2) = sqrt ((x1-x2)^2 + (y1-y2)^2)

perimeter (p1 : p2 : ps) = distance p1 p2 + perimeter (p2 : ps)
perimeter _ = 0

main = do
    n <- liftM read getLine
    ps <- replicateM n $ do
        [x, y] <- liftM (map read . words) getLine :: IO [Double]
        return (x, y)

    print $ perimeter $ ps ++ [head ps]

