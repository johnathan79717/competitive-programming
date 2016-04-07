import Control.Monad
import Prelude hiding (readList)

readLine = liftM read getLine
readList = liftM (map read . words) getLine

main = do
    inputs <- liftM lines getContents
