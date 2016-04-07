import Control.Monad

main = do
    t <- readLn
    arrs <- replicateM t $ liftM (map read . words) getLine :: IO [[Int]]
    let
        merge :: [Int] -> [Int] -> [Int]
        merge [] _ = []
        merge _ [] = []
        merge t1@(p1:n1:ts1) t2@(p2:n2:ts2) = if p1 < p2 then merge ts1 t2 else
            if p1 > p2 then merge t1 ts2 else p1:min n1 n2:merge ts1 ts2
    putStrLn $ unwords $ map show $ foldl1 merge arrs
