import Control.Monad

unique [] = True
unique (x:xs) = not (elem x xs) && unique xs    

main = do
    t <- liftM read getLine :: IO Int
    replicateM_ t $ do
        n <- liftM read getLine :: IO Int
        xs <- replicateM n $ do
            liftM (read . head . words) getLine :: IO Int
        {-print xs-}
        putStrLn $ if unique xs then "YES" else "NO"
