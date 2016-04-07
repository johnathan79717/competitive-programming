import Control.Applicative((<*))
import qualified Data.Map as M
import qualified Control.Monad.State as S
import Text.Parsec
import Text.Parsec.String
import Text.Parsec.Expr
import Text.Parsec.Token
import Text.Parsec.Language
import Debug.Trace

data Op = Add | Sub | Mul | Div | And | Or | Gt | Lt deriving Show
data Exp = Var String | Num Integer | Op Op Exp Exp | Bool Bool deriving Show
data Stmt = String := Exp | If Exp Stmt Stmt | While Exp Stmt | Seq [Stmt] deriving Show

def = emptyDef{ commentStart = "["
              , commentEnd = "]"
              , identStart = letter
              , identLetter = alphaNum
              , opStart = oneOf "+-*/><:"
              , opLetter = oneOf "+-*/><:="
              , reservedOpNames = ["+", "-", "*", "/", ">", "<", ":="]
              , reservedNames = ["true", "false", "and", "or",
                                 "if", "then", "else", "while", "do"]
              }

TokenParser{ parens = m_parens
           , braces = m_braces
           , identifier = m_identifier
           , natural = m_natural
           , reservedOp = m_reservedOp
           , reserved = m_reserved
           , semiSep1 = m_semiSep1
           , whiteSpace = m_whiteSpace } = makeTokenParser def

expr :: Parser Exp
expr = buildExpressionParser table term <?> "expression"
table = [ [ Infix (m_reservedOp "*" >> return (Op Mul)) AssocLeft
          , Infix (m_reservedOp "/" >> return (Op Div)) AssocLeft
          ]
        , [ Infix (m_reservedOp "+" >> return (Op Add)) AssocLeft
          , Infix (m_reservedOp "-" >> return (Op Sub)) AssocLeft
          ]
        , [ Infix (m_reservedOp ">" >> return (Op Gt)) AssocLeft
          , Infix (m_reservedOp "<" >> return (Op Lt)) AssocLeft
          ]
        , [ Infix (m_reserved "and" >> return (Op And)) AssocLeft
          , Infix (m_reserved "or" >> return (Op Or)) AssocLeft
          ]
        ]
term = m_parens expr
       <|> fmap Var m_identifier
       <|> fmap Num m_natural

while :: Parser Stmt
while = m_whiteSpace >> stmt <* eof
    where
      stmt :: Parser Stmt
      stmt = fmap Seq (m_semiSep1 stmt')
      stmt' = do { v <- m_identifier
                 ; m_reservedOp ":="
                 ; e <- expr
                 ; return (v := e)
                 }
          <|> do { m_reserved "if"
                 ; b <- expr
                 ; m_reserved "then"
                 ; p <- m_braces stmt
                 ; m_reserved "else"
                 ; q <- m_braces stmt
                 ; return (If b p q)
                 }
          <|> do { m_reserved "while"
                 ; b <- expr
                 ; m_reserved "do"
                 ; p <- m_braces stmt
                 ; return (While b p)
                 }

type Env = M.Map String (Either Bool Integer)

eval :: Exp -> S.State Env (Either Bool Integer)
eval (Var s) = do
  env <- S.get
  return (env M.! s)
eval (Num i) = return (Right i)
eval (Bool b) = return (Left b)
eval (Op op e1 e2) = do
  v1 <- eval e1
  v2 <- eval e2
  return $ case op of
    Add -> let (Right v1') = v1; (Right v2') = v2 in Right $ v1' + v2'
    Sub -> let (Right v1') = v1; (Right v2') = v2 in Right $ v1' - v2'
    Mul -> let (Right v1') = v1; (Right v2') = v2 in Right $ v1' * v2'
    Div -> let (Right v1') = v1; (Right v2') = v2 in Right $ div v1' v2'
    Gt  -> let (Right v1') = v1; (Right v2') = v2 in Left  $ v1' > v2'
    Lt  -> let (Right v1') = v1; (Right v2') = v2 in Left  $ v1' < v2'
    And -> let (Left  v1') = v1; (Left  v2') = v2 in Left  $ v1' && v2'
    Or  -> let (Left  v1') = v1; (Left  v2') = v2 in Left  $ v1' || v2'

exec :: Stmt -> S.State Env ()
exec (s := e) = do
  v <- eval e
  env <- S.get
  S.put $ M.insert s v env
exec (If b p q) = do
  Left v <- eval b
  if v then exec p else exec q
exec (While b p) = do
  Left v <- eval b
  S.when v $ exec (Seq [p, While b p])
exec (Seq ss) = mapM_ exec ss

--main = do
--  prog <- getContents
--  let env = M.assocs $ case parse while "" prog of Left err -> error ""; Right ast -> S.execState (exec ast) $ M.fromList []
--  S.forM_ env (\(s, Right v) -> do
--    putStr (s ++ " ")
--    print v
--    )