import Control.Monad
import Data.Array
import Data.Bits
import Data.Char
import Debug.Trace
import Numeric
import Control.Exception hiding (mask)

toInt = helper 0 where
    helper a [] = a
    helper a (x:xs) = helper (shiftL a 1 .|. x) xs
double k j = mask k .&. shiftL j 1
stateToOutput g j = map (\g -> popCount (j .&. g) .&. 1) g
mask = ((-1)+) . shiftL 1
main = do
    nk1 : inputs <- liftM lines getContents    
    let
        readBin = fst . head . readInt 2 (flip elem "01") digitToInt
        [n1, k1] = map read $ words nk1
        (g1', nk2 : input2) = splitAt n1 inputs
        g1 = map readBin g1'
        [n2, k2] = map read $ words nk2
        (g2', message') = splitAt n2 input2
        seg = segment $ concat message' where
            segment [] = []
            segment xs = let (a, as) = splitAt n1 xs in readBin a : segment as
        message = listArray (1, length seg) seg
        m = snd $ bounds message
        dp = listArray ((0, 0), (m, mask k1)) [f i j | i <- [0..m], j <- [0..mask k1]] where
            f 0 0 = (0, -1)
            f 0 _ = (1000000000000000000, -1)
            f i j = let
                reg = double k1 j
                d = popCount $ xor (toInt $ stateToOutput g1 j) $ message ! i
                in min (d + fst (dp ! (i-1, reg)), -reg) (d + fst (dp ! (i-1, reg+1)), -reg-1)
    let
        source = reverse $ (replicate k2 0 ++) $ drop k1 $ recover m 0 where
            recover 0 _ = []
            recover i j = assert (ans == 1 || ans == 0) ans : (recover (i-1) $ (*(-1)) $ snd $ dp ! (i, j)) where
                ans = shiftR j (k1 - 1)

        g2 = map readBin g2'
        encode _ [] = []
        encode state (m:ms) = stateToOutput g2 newState : encode newState ms where
            newState = shiftR state 1 .|. if m == 0 then 0 else shiftL 1 (k2-1)
    -- print source
    putStrLn $ map intToDigit $ concat $ encode 0 source

