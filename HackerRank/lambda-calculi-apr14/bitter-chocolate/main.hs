import Control.Monad
import Data.Array
import Data.List

main = do
  let
    dp = array ((0, 0, 0), (25, 25, 25)) $ map f [(r1, r2, r3) | r1 <- [0..25], r2 <- [0..r1], r3 <- [0..r2]]
    f (0, 0, 0) = ((0, 0, 0), True)
    f (r1, r2, r3) = ((r1, r2, r3),
      not . and . map (dp !) $ ([(r1, r2, k) | k <- [0..r3-1]]
      ++ [(r1, j, min j r3) | j <- [0..r2-1]]
      ++ [(i, min i r2, min i r3) | i <- [0..r1-1]]))
  getLine
  rss <- liftM lines getContents
  forM_ rss (\rs -> let [r1, r2, r3] = (map read . words) rs
                    in putStrLn $ if dp ! (r1, r2, r3) then "WIN" else "LOSE")
