import Data.List

primes :: [Int]
primes = sieve [2..]

sieve :: [Int] -> [Int]
sieve (p:xn) = p : sieve [x | x <- xn, x `mod` p /= 0]

dict :: [(Int, Int)]
dict = map (\x -> (head x, length x)) $ group $ sort $ filter (< 10001) [ p + 2*q | q <- takeWhile (<5000) primes, p <- takeWhile (<(10001-2*q)) primes]

table :: [Int]
table = [ case (lookup n dict) of Nothing -> 0; Just x -> x | n <- [0..10000] ]