import Control.Monad

main = do
    inputs <- liftM lines getContents
    putStrLn $ map head $ words $ head inputs