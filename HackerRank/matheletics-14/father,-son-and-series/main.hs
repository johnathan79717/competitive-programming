series 1 = [10]
series n = let x:xs = series (n-1) in if x < 3 || x `div` 3 `elem` xs then (x*7):x:xs else (x`div`3):x:xs