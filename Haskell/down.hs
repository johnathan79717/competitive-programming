down [] = []
down (x:xs) = ([x]:(down xs))
