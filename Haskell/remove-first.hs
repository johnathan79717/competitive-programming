remove_first :: Int -> [Int] -> [Int]
remove_first _ [] = []
remove_first n (x:xs) | n == x = xs
                      | otherwise = (x:(remove_first n xs))
