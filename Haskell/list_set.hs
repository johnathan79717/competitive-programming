list_set (x:xs) n a | n == 0 = (a:xs)
                    | otherwise = (x:(list_set xs (n-1) a))
