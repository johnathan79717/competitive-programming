import Control.Monad
import Data.Set (Set)
import qualified Data.Set as Set

main = do
    str <- getLine
    let
        solve [] _ = ""
        solve (s:ss) set = if Set.member s set then solve ss set else s : solve ss (Set.insert s set)
    putStrLn $ solve str Set.empty