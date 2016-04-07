mymap :: (a -> b) -> [a] -> [b]
mymap f = foldr (\x xs -> (f x):xs) []
