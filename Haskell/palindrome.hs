palindrome :: Show a => a -> Bool
palindrome x = s == reverse s where s = show x

make_palindrome :: (Show a, Read a) => a -> a
make_palindrome x = let s = show x
    in read $ s ++ reverse s

make_palindrome' :: (Show a, Read a) => a -> a
make_palindrome' x = let s = show x
    in read $ s ++ tail (reverse s)
