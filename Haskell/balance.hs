balance :: String -> Bool
balance = balance' 0 where
  balance' 0 "" = True
  balance' _ "" = False
  balance' n (c : cs)
    | n < 0     = False
    | c == '('  = balance' (n+1) cs
    | c == ')'  = balance' (n-1) cs
    | otherwise = balance' n cs