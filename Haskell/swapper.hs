swapper _ _ [] = []
swapper s1 s2 (x:xs) | x == s1 = (s2:(swapper s1 s2 xs))
                     | x == s2 = (s1:(swapper s1 s2 xs))
                     | otherwise = (x:(swapper s1 s2 xs))
