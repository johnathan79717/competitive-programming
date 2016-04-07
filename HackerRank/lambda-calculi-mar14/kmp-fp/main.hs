import Control.Monad
import Data.Array
import Data.Array.IO
import Debug.Trace

kmp_table w t = do
  writeArray t 0 (-1)
  if snd (bounds w) >= 1 then writeArray t 1 0 else return ()
  while 2 0
    where
      while pos cnd
        | pos > snd (bounds w) = return ()
        | (w ! (pos - 1)) == (w ! cnd) = do
          writeArray t pos (cnd + 1)
          while (pos + 1) (cnd + 1)
        | cnd > 0 = do
          cnd' <- readArray t cnd
          while pos cnd'
        | otherwise = do
          writeArray t pos 0
          while (pos + 1) cnd

kmp_search s w t = do
  while 0 0 where
    while m i
      | m + i > snd (bounds s) = return False
      | (w ! i) == (s ! (m + i)) =
        if i == snd (bounds w) then
          return True
        else
          while m (i+1)
      | otherwise = do
        ti <- readArray t i
        if ti > -1 then
          while (m + i - ti) ti
        else
          while (m + i - ti) 0

main = do
  tt <- liftM read getLine
  replicateM_ tt (do
    text <- getLine
    pat <- getLine
    let s = listArray (0, length text - 1) text
    let w = listArray (0, length pat - 1) pat
    t <- newArray_ (bounds w) :: IO (IOArray Int Int)
    kmp_table w t
    ans <- kmp_search s w t
    if ans then putStrLn "YES" else putStrLn "NO"
    )