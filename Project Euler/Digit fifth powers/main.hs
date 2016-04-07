import Data.Char

f n = (==) n $ sum $ map ((^4) . digitToInt) $ show n
