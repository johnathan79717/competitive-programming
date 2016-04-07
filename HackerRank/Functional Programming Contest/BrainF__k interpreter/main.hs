import Control.Monad
import Data.Array.IArray
import Data.Array.IO
import Data.Char
import Debug.Trace

interpret ops program inst_ptr memory data_ptr input leftBracket rightBracket
  -- | traceShow (ops, inst_ptr) 0 = return ()
  | inst_ptr > (snd $ bounds program) = return ()
  | ops >= 100000 = putStr "\nPROCESS TIME OUT. KILLED!!!"
  | leftBracket > 0 = case program ! inst_ptr of
    '[' -> interpret ops program (inst_ptr+1) memory data_ptr input (leftBracket+1) 0
    ']' -> if leftBracket == 1
      then interpret (ops+1) program (inst_ptr+1) memory data_ptr input 0 0
      else interpret ops program (inst_ptr+1) memory data_ptr input (leftBracket-1) 0
    otherwise -> interpret ops program (inst_ptr+1) memory data_ptr input leftBracket 0
  | rightBracket > 0 = case program ! inst_ptr of
    ']' -> interpret ops program (inst_ptr-1) memory data_ptr input 0 (rightBracket+1)
    '[' -> if rightBracket == 1
      then interpret (ops+1) program (inst_ptr+1) memory data_ptr input 0 0
      else interpret ops program (inst_ptr-1) memory data_ptr input 0 (rightBracket-1)
    otherwise -> interpret ops program (inst_ptr-1) memory data_ptr input 0 rightBracket
  | otherwise = do
    case program ! inst_ptr of
      '>' -> interpret (ops+1) program (inst_ptr+1) memory (data_ptr+1) input 0 0
      '<' -> interpret (ops+1) program (inst_ptr+1) memory (data_ptr-1) input 0 0
      '+' -> do
        byte <- readArray memory data_ptr
        if byte == 255
          then writeArray memory data_ptr 0
          else writeArray memory data_ptr (byte+1)
        interpret (ops+1) program (inst_ptr+1) memory data_ptr input 0 0
      '-' -> do
        byte <- readArray memory data_ptr
        if byte == 0
          then writeArray memory data_ptr 255
          else writeArray memory data_ptr (byte-1)
        interpret (ops+1) program (inst_ptr+1) memory data_ptr input 0 0
      '.' -> do
        byte <- readArray memory data_ptr
        putChar (chr byte)
        interpret (ops+1) program (inst_ptr+1) memory data_ptr input 0 0
      ',' -> do
        writeArray memory data_ptr (ord $ head input)
        interpret (ops+1) program (inst_ptr+1) memory data_ptr (tail input) 0 0
      '[' -> do
        byte <- readArray memory data_ptr
        if byte == 0
          then interpret (ops+1) program (inst_ptr+1) memory data_ptr input 1 0
          else interpret (ops+1) program (inst_ptr+1) memory data_ptr input 0 0
      ']' -> do
        byte <- readArray memory data_ptr
        if byte /= 0
          then interpret (ops+1) program (inst_ptr-1) memory data_ptr input 0 1
          else interpret (ops+1) program (inst_ptr+1) memory data_ptr input 0 0
      --otherwise -> interpret ops program (inst_ptr+1) memory data_ptr input 0 0

main = do
  [n, m] <- liftM (map read . words) getLine
  input <- getLine
  string <- liftM concat $ replicateM m getLine
  let string' = filter (\c -> elem c "><+-.,[]") string
  let program = listArray (0, length string' - 1) string' :: Array Int Char
  memory <- newArray (0, 100000) 0 :: IO (IOArray Int Int)
  interpret 0 program 0 memory 0 input 0 0
