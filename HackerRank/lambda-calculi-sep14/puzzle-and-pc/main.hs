import Control.Monad

main = do
    m <- readLn :: IO Int
    [r, c] <- liftM (map read . words) getLine :: IO [Int]
    let
        f 0 _ _ _ _ = return ()
        f m r c or oc = do
            if r <= half && c <= half
                then (do
                    putStrLn $ unwords $ map show $ (tr ++ bl ++ br)
                    f (m-1) r c or oc)
                else
                    f (m-1) half half or oc
            if r <= half && c > half
                then (do
                    putStrLn $ unwords $ map show $ (tl ++ bl ++ br)
                    f (m-1) r (c - half) or (oc + half))
                else
                    f (m-1) half 1 or (oc + half)
            if r > half && c <= half
                then (do
                    putStrLn $ unwords $ map show $ (tl ++ tr ++ br)
                    f (m-1) (r-half) c (or + half) oc)
                else
                    f (m-1) 1 half (or + half) oc
            if r > half && c > half
                then (do
                    putStrLn $ unwords $ map show $ (tl ++ tr ++ bl)
                    f (m-1) (r-half) (c-half) (or+half) (oc + half))
                else
                    f (m-1) 1 1 (or + half) (oc + half) 
            where
                half = 2 ^ (m-1)
                tl = [half + or, half + oc]
                tr = [half + or, half + 1 + oc]
                bl = [half + 1 + or, half + oc]
                br = [half + 1 + or, half + 1 + oc]
    f m r c 0 0


