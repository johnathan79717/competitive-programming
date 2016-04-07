sort [] = []
sort (x:xs) = isrt x (sort xs)

isrt x [] = [x]
isrt x (y:ys) | x <= y = x:(y:ys)
              | otherwise = y:(isrt x ys)
