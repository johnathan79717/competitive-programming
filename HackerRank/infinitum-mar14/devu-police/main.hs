import Control.Monad
import Data.List

primes = sieve [2..] where
  sieve (x:xs) = x : sieve (filter (\y->mod y x /= 0) xs)

factor 1 = []
factor n = case find (\x->mod n x == 0) (takeWhile (\p->p*p<=n) primes) of
  Nothing -> [(n, 1)]
  Just p -> let Just k = findIndex (\x->mod n (p^x) /= 0) [1..]
            in (p, k):factor (div n (p^k))

inverse a m = while a m 0 1 where
  while 0 1 x _ = mod (x + m) m
  while 0 _ _ _ = error ""
  while a d x s = while r a s t where
    q = div d a
    r = mod d a
    t = x - q * s

main = do
  t <- liftM read getLine
  replicateM_ t (do
    [n1, k1, n2, k2, n] <- liftM (map read . words) getLine
    let f1' = n1 ^ k1
    let f2 = n2 ^ k2
    if f1' == 0 && f2 == 0 then print (mod 1 n) else (do
      let f1 = mod f1' n
      if f2 < 25 then print (mod (f1 ^ f2) n) else (do
        let pk = factor n
        let xs = map (\(p, k)->if mod f1 p == 0 then 0 else mod (f1 ^ (mod f2 (p^k - p^(k-1)))) (p^k)) pk
        return ()
        let ys = map (\(p, k)->let m = div n (p^k) in m * inverse m (p^k)) pk
        print $ mod (sum (zipWith (*) xs ys)) n
        )
      )
    )