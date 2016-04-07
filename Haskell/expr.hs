data Expr = Val Int | Add Expr Expr | Mul Expr Expr

instance Show Expr where
  show (Val n) = "Val " ++ show n
  show (Add e1 e2) = "Add (" ++ show e1 ++ ") (" ++ show e2 ++ ")"
  show (Mul e1 e2) = "Mul (" ++ show e1 ++ ") (" ++ show e2 ++ ")"

eval :: Expr -> Int
eval (Val n) = n
eval (Add x y) = eval x + eval y
eval (Mul x y) = eval x * eval y