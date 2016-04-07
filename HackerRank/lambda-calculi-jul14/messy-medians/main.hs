import Control.Monad
--import qualified Data.Sequence as S hiding (replicateM)
import Data.Sequence
import Prelude hiding (splitAt, length)
import Debug.Trace

median state = let n = length state in index state (div (n-1) 2)
search back a = helper (-1) n where
  n = length back
  helper lb ub
    | ub - lb <= 1 = ub
    | otherwise = let m = div (lb + ub) 2 in
      if index back m < a then helper m ub else helper lb m
insert back i a = let (l, r) = splitAt i back in (l |> a) >< r

main = do
  a <- liftM (map read . tail . lines) getContents
  let
    run [] _ = []
    run (a:as) states
      | traceShow back False = undefined
      | a < 0 = let n = length states in
        let newState = index states (n+a) in
        median newState : run as (states |> newState)
      | otherwise = let
        i = search back a
        newState = insert back i a
        in median newState : run as (states |> newState)
          where (_ :> back) = viewr states
  putStr $ unlines $ map show $ run a $ singleton empty