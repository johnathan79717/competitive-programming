select :: [a] -> Int -> a
select (x:_) 0 = x
select (_:xs) n = select xs (n-1)
