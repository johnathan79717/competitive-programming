myfilter p = foldr (\ x xs -> if p x then x:xs else xs) []
