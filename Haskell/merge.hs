merge [] l = l
merge l [] = l
merge (x:xs) (y:ys) | x <= y = x:(merge xs (y:ys))
                    | otherwise = y:(merge (x:xs) ys)

msort :: [Int] -> [Int]
msort [] = []
msort [x] = [x]
msort xs = merge (msort ys) (msort zs)
           where ys = [x | (x, i) <- zip xs [0..(length xs - 1)], 2 * i < length xs]
                 zs = [x | (x, i) <- zip xs [0..(length xs - 1)], 2 * i >= length xs]
