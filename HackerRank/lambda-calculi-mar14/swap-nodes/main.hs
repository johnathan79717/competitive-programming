import Control.Monad
import Data.Array.IO
import Data.Array

main = do
  n <- liftM read getLine
  depth <- newArray_ (1, n) :: IO (IOArray Int Int)
  writeArray depth 1 1
  child' <- mapM (\i -> do
    [a, b] <- liftM (map read . words) getLine
    d <- readArray depth i 
    if a > 0 then writeArray depth a (d+1) else return ()
    if b > 0 then writeArray depth b (d+1) else return ()
    return (a, b)
    ) [1..n]
  let child = listArray (1, n) child'
  t <- liftM read getLine
  swap <- newArray (1, n) False :: IO (IOArray Int Bool)
  replicateM_ t (do
    k <- liftM read getLine
    mapM_ (\i -> do
      swap' <- readArray swap i
      writeArray swap i $ not swap'
      ) [k, k+k .. n]
    let inorder i = if i < 0 then return () else do
        let (a, b) = child ! i
        d <- readArray depth i
        swap' <- readArray swap d
        if swap' then (do
          inorder b
          putStr (show i ++ " ") 
          inorder a
          )
          else (do
            inorder a
            putStr (show i ++ " ")
            inorder b
            )
    inorder 1
    putStrLn ""
    )