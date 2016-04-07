myreplicate :: Int -> a -> [a]
myreplicate 0 _ = []
myreplicate n x = x:(myreplicate (n-1) x) 
