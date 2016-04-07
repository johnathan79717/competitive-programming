data Tree = Leaf Int | Node Tree Int Tree

instance Show Tree where
  show (Leaf n) = "Leaf " ++ show n
  show (Node t1 n t2) = "Node (" ++ show t1 ++ ") " ++ show n ++ " (" ++ show t2 ++ ")"

complete :: Tree -> Bool
complete (Leaf _) = True
complete (Node t1 _ t2) = (complete t1) && (complete t2) && (size t1 == size t2)

size :: Tree -> Int
size (Leaf _) = 1
size (Node t1 _ t2) = size t1 + size t2