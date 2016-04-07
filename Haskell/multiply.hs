data Nat = Zero | Succ Nat

add Zero n = n
add (Succ m) n = Succ (add m n)

multiply Zero n = Zero
multiply (Succ Zero) n = n
multiply (Succ m) n = add (multiply m n) n

instance Show Nat where
  show Zero = "Zero"
  show (Succ n) = "(Succ " ++ show n ++ ")"