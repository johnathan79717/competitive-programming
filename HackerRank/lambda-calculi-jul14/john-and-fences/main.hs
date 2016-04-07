import Control.Monad
import Debug.Trace

main = do
  n <- readLn
  h <- liftM (map read . words) getLine
  let
    --solve h stack ans i | traceShow (h, stack, ans, i) False = undefined
    solve [] stack ans _ = final stack ans
    solve ha@(h:hs) stack ans i
      | (not.null) stack && fst (head stack) >= h =
        --traceShow "this case" $ 
        let (prev, s):stack' = stack in
          if null stack' then solve ha stack' (max ans (prev * i)) i
            else solve ha stack' (max ans (prev * (i - 1 - (snd $ head stack')))) i
      | otherwise = solve hs ((h, i):stack) ans (i+1)
    final [] ans = ans
    final ((f, s):tl) ans = if null tl then max ans (f * n)
      else final tl $ max ans $ f * (n - 1 - s)
  print $ solve h [] 0 0