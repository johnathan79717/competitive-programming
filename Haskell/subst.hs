subst :: Int -> Int -> [Int] -> [Int]
subst _ _ [] = []
subst new old (x:xs) | x == old = (new:(subst new old xs))
                     | otherwise = (x:(subst new old xs))
