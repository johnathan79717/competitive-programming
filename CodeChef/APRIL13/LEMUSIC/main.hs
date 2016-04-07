import Control.Monad
import qualified Data.Map as Map
import Data.List

solve :: [(Int, Int)] -> Int
solve songs = 
  let shortSongs = sortBy (\(_, x) (_, y) -> compare x y) $ Map.toList $ Map.fromListWith min songs
      shortSweetness = sum $ zipWith (\(_, l) u -> l * u) shortSongs [1..]
      longSongs = songs \\ shortSongs
      longSweetness = length shortSongs * foldr (\acc (_, l) -> acc + l) 0 longSongs
  in shortSweetness + longSweetness

main = do
  t <- liftM read getLine
  replicateM_ t $ do
    n <- liftM read getLine
    songs <- replicateM n $ do
      liftM ( (\[b, l] -> (read b, read l)) . words) getLine
    print $ solve songs


