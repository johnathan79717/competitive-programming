isPalindrome n = s == reverse s where s = show n

a = filter isPalindrome [10..1000]

ans = maximum [(i * j * k, i, j, k) | i <- a, j <- a, j /= i, k <- a, k /= i, k /= j, isPalindrome (i + j + k)]

main = print ans
