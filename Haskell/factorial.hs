--factorial 0 = 1
--factorial n = n * factorial (n-1)

factorial = factorial' 1 where
  factorial' c 0 = c
  factorial' c n = factorial' (c*n) (n-1)

fact 0 = [1]
fact n = let x:xs = fact (n-1) in (n*x):x:xs

main = print $ sum $ map (read . reverse . take 18 . reverse . filter (/='0') . show) $ fact 1000