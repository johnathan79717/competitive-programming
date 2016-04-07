import Data.List

factors :: Int -> [Int]
factors n = case find (\x -> n `mod` x == 0) [2..round $ sqrt $ fromIntegral n] of
                 Nothing -> [n]
                 Just p  -> p : factors (divAll n p)

divAll n p | mod n p == 0 = divAll (div n p) p
           | otherwise    = n
