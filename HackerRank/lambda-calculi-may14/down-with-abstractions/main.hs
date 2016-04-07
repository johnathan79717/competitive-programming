import Control.Monad
import Text.Parsec
import Text.Parsec.String
import Text.Parsec.Expr
import Text.Parsec.Token
import Text.Parsec.Language
import Debug.Trace
import Data.Set (Set)
import Debug.Trace
import qualified Data.Set as Set

--EXP = VAR
--EXP = '(' EXP ' ' EXP ')'
--EXP = '(' '\' VARLIST '.' EXP ')'
--VARLIST = VAR VARLIST0
--VARLIST0 = eps
--VARLIST0 = ' ' VAR VARLIST0

type Free = Set String
data Expr = K | S | I | C | B |
  Var String | App Expr Expr Free | Abs String Expr Free deriving Show

free :: Expr -> Free
free (Var s) = Set.singleton s
free (App _ _ f) = f
free (Abs _ _ f) = f
free _ = Set.empty

def = emptyDef{ commentStart = "["
              , commentEnd = "]"
              , identStart = alphaNum <|> char '_'
              , identLetter = alphaNum <|> char '_'
              , opStart = oneOf "\\."
              , opLetter = oneOf "\\."
              , reservedOpNames = ["\\", "."]
              , reservedNames = []
              }

TokenParser{ parens = m_parens
           , identifier = m_identifier
           , reservedOp = m_reservedOp
           , whiteSpace = m_whiteSpace } = makeTokenParser def

term :: Parser Expr
term = m_parens expr
  <|>
  do { s <- m_identifier
     ; return $ Var s
     } 
expr :: Parser Expr
expr =
  do { e1 <- term
     ; e2 <- term
     ; return $ App e1 e2 (Set.union (free e1) (free e2))
     }
  <|> 
  do { m_reservedOp "\\"
     ; vs' <- many1 m_identifier
     ; m_reservedOp "."
     ; e' <- term
     ; let
         abs' (v:vs) e = let rec = abs' vs e in Abs v rec (Set.delete v $ free rec)
         abs' [] e = e
         in return $ abs' vs' e'
     }

reduce :: Expr -> Expr
--reduce e | traceShow e False = undefined
reduce e | basis e = e
reduce s@(Var _) = s
reduce (App e1 e2 f) = App (reduce e1) (reduce e2) f
reduce (Abs x e f) | Set.notMember x (free e) = App K (reduce e) f
reduce (Abs x (Var x') _) | x == x' = I
reduce (Abs x ey@(Abs _ _ _) fx) = reduce (Abs x (reduce ey) fx)
reduce (Abs x (App e (Var x') _) _) | x == x' && Set.notMember x (free e) = reduce e
reduce (Abs x (App e1 e2 _) fx) | Set.notMember x (free e1) =
  App (App B (reduce e1) $ free e1) (reduce $ Abs x e2 $ Set.delete x $ free e2) fx
reduce (Abs x (App e1 e2 _) fx) | Set.notMember x (free e2) = let f1' = Set.delete x $ free e1 in
  App (App C (reduce $ Abs x e1 $ f1') f1') (reduce e2) fx
reduce (Abs x (App e1 e2 _) fx) | otherwise = let f1' = Set.delete x $ free e1 in
  App (App S (reduce $ Abs x e1 f1') f1') (reduce $ Abs x e2 $ Set.delete x $ free e2) fx
--reduce K = K
--reduce S = S
--reduce I = I
--reduce B = B
--reduce C = C

basis :: Expr -> Bool
basis K = True
basis S = True
basis I = True
basis B = True
basis C = True
basis _ = False

show' :: Expr -> String
show' e | basis e = show e
show' (App e1 e2 _) = show' e1 ++ if basis e2 then show' e2 else "(" ++ show' e2 ++ ")"
--show' (Var s) = s
--show' e = traceShow e undefined
--show' e = ""

main = do
  t <- readLn
  replicateM_ t (do
    input <- getLine
    let Right e = parse term "" input
    --print e
    --print $ reduce e
    putStrLn $ show' $ reduce e
    )