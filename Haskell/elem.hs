myelem :: Eq a => a -> [a] -> Bool
myelem _ [] = False
myelem a (x:xs) | x == a = True
              | otherwise = myelem a xs
