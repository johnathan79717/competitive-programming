every _ [] = True
every pred (x:xs) | pred x = every pred xs
                  | otherwise = False
