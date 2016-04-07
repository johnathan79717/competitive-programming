exists _ [] = False
exists pred (x:xs) | pred x = True
                   | otherwise = exists pred xs
