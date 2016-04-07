import Data.Maybe
import Control.Monad
import qualified Data.Map as M

type Var Int

data Simple = Name String | Var Var | Rel String [Simple]
  deriving Show
data Complex = Simple Simple | Condition Condition
  deriving Show
data Rule = Rule [Complex] Simple
  deriving Show
data Condition = Eq Simple Simple | Neq Simple Simple deriving Show

--rules = [ Rule [] $ Rel "r" [Name "a"]
--        , Rule [Simple $ Rel "r" [Var "z"]] $ Rel "p" [Rel "r" [Var "z"], Var "z"]]

--q1 = [Simple $ Rel "p" [Rel "r" [Name "a"], Name "a"]]
--q2 = [Simple $ Rel "p" [Var "a", Name "a"]]
--q3 = [Simple $ Rel "p" [Var "a", Name "b"]]
--q4 = [Simple $ Rel "p" [Rel "r" [Name "a"], Var "a"]]
--q5 = [Simple $ Rel "p" [Var "a", Var "b"]]
--q6 = [Simple $ Rel "p" [Var "c", Var "c"]]
--q7 = [Simple $ Rel "p" [Var "a", Var "b"], Condition $ Eq (Var "a") (Var "b")]
--q8 = [Simple $ Rel "p" [Var "a", Var "b"], Condition $ Neq (Var "a") (Var "b")]
--q9 = [Simple $ Rel "p" [Var "a", Var "b"], Condition $ Eq (Name "a") (Var "b")]

rules = [ Rule [] $ Rel "lt-n" [Name "a", Name "b"]
        , Rule [] $ Rel "lt-n" [Name "b", Name "c"]
        , Rule [Simple $ Rel "lt-n" [Var 0, Var 1]] $ Rel "lt" [Var 0, Var 1]
        , Rule [Simple $ Rel "lt-n" [Var 2, Var 3]
               , Simple $ Rel "lt" [Var 3, Var 4]] $ Rel "lt" [Var 2, Var 4 ]
        ]
q = [Simple $ Rel "lt" [Var 8, Var 9]]

match :: Simple -> Simple -> Maybe [Condition]
match (Name s1) (Name s2) | s1 == s2 = Just [] | otherwise = Nothing
match (Name _) (Rel _ _) = Nothing
match (Rel _ _) (Name _) = Nothing
match (Rel s1 simple1) (Rel s2 simple2)
  | s1 /= s2 = Nothing
  | otherwise = process simple1 simple2 where
    process [] [] = Just []
    process [] _ = Nothing
    process _ [] = Nothing
    process (x:xs) (y:ys) = do
      m <- match x y
      ms <- process xs ys
      return (m ++ ms)
match x y = Just [Eq x y]

verify :: M.Map Var Simple -> [Complex] -> [[Condition]]
verify [] = [[]]
verify (q:qs) = case q of
  Condition cond -> map (cond:) $ verify qs
  Simple simple ->  concat $ map try rules where
    try :: Rule -> [[Condition]]
    try (Rule premises conclusion) =
      case match conclusion simple of
        Nothing -> []
        Just conds -> map (conds ++) $ verify (premises ++ qs)
