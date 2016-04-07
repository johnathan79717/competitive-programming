prod [] _ = []
prod _ [] = []
prod (x:xs) (y:ys) = [[x, y]] ++ (prod [x] ys) ++ (prod xs [y]) ++ (prod xs ys)
