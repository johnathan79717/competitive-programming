count_occurrences _ [] = 0
count_occurrences a (x:xs) | x == a    = count_occurrences a xs + 1
                           | otherwise = count_occurrences a xs
