import Control.Monad
import Data.Char

main = do
    inputs <- liftM lines getContents
    let input = head inputs
    let
        f :: (String, String) -> Char
        f (a, b) = let i = read a in if i < length b then b !! i else ' '
    putStrLn $ map (f . span isDigit) $ words input