filter_in _ [] = []
filter_in pred (x:xs) | pred x    = x:(filter_in pred xs)
                      | otherwise = filter_in pred xs
