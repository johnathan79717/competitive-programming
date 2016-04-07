list_index _ [] = -1
list_index pred (x:xs) | pred x = 0
                       | otherwise = list_index pred xs + 1
