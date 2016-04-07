number_elements_from :: Int -> [Int] -> [[Int]]
number_elements_from _ [] = []
number_elements_from n (x:xs) = ([n, x]:(number_elements_from (n+1) xs))

number_elements = number_elements_from 0
