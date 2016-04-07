count 1000 = 11 -- one thousand
count 90 = 6 -- ninety
count 80 = 6 -- eighty
count 70 = 7 -- seventy
count 60 = 5 -- sixty
count 50 = 5 -- fifty
count 40 = 5 -- forty
count 30 = 6 -- thirty
count 20 = 6 -- twenty
count 19 = 8 -- nineteen
count 18 = 8 -- eighteen
count 17 = 9 -- seventeen
count 16 = 7 -- sixteen
count 15 = 7 -- fifteen
count 14 = 8 -- fourteen
count 13 = 8 -- thirteen
count 12 = 6 -- twelve
count 11 = 6 -- eleven
count 10 = 3 -- ten
count 9 = 4 -- nine
count 8 = 5 -- eight
count 7 = 5 -- seven
count 6 = 3 -- six
count 5 = 4 -- five
count 4 = 4 -- four
count 3 = 5 -- three
count 2 = 3 -- two
count 1 = 3 -- one
count 0 = 0

count x
  | x >= 100 = let (q, r) = divMod x 100 in if r == 0 then count q + 7 else count q + 10 + count r
  | otherwise = let r = mod x 10 in count (x - r) + count r


--letter 1000 = "one thousand"
letter 90 = "Ninety"
letter 80 = "Eighty"
letter 70 = "Seventy"
letter 60 = "Sixty"
letter 50 = "Fifty"
letter 40 = "Forty"
letter 30 = "Thirty"
letter 20 = "Twenty"
letter 19 = "Nineteen"
letter 18 = "Eighteen"
letter 17 = "Seventeen"
letter 16 = "Sixteen"
letter 15 = "Fifteen"
letter 14 = "Fourteen"
letter 13 = "Thirteen"
letter 12 = "Twelve"
letter 11 = "Eleven"
letter 10 = "Ten"
letter 9 = "Nine"
letter 8 = "Eight"
letter 7 = "Seven"
letter 6 = "Six"
letter 5 = "Five"
letter 4 = "Four"
letter 3 = "Three"
letter 2 = "Two"
letter 1 = "One"
letter 0 = ""

letter x
  | x >= 10^9 = let (q, r) = divMod x (10^9) in letter q ++ " Billion " ++ letter r
  | x >= 10^6 = let (q, r) = divMod x (10^6) in letter q ++ " Million " ++ letter r
  | x >= 1000 = let (q, r) = divMod x (1000) in letter q ++ " Thousand " ++ letter r
  | x >= 100 = let (q, r) = divMod x 100 in letter q ++ " Hundred " ++ letter r
  | otherwise = let r = mod x 10 in letter (x - r) ++ " " ++ letter r