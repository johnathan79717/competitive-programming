import Control.Applicative((<*))
import qualified Data.Map as M
import qualified Control.Monad.State as S
import Text.Parsec
import Text.Parsec.String
import Text.Parsec.Expr
import Text.Parsec.Token
import Text.Parsec.Language
import Debug.Trace
import Data.Ratio
import Data.List

data Op = Add | Sub | Mul | Div deriving Show
data Expr = Neg Expr | Op Op Expr Expr | Num Rational | FValue String [Expr] deriving Show
data Stmt = String := [Rational]
          | Do Expr [(String, Expr)] | What [(String, [Expr])] deriving Show

def = emptyDef{ commentStart = ""
              , commentEnd = ""
              , identStart = letter
              , identLetter = alphaNum
              , opStart = oneOf "+-*/.!?:"
              , opLetter = oneOf "+-*/.!?:"
              , reservedOpNames = ["+", "-", "*", "/", ".", "!", ":", "?"]
              , reservedNames = ["is", "of", "assign", "what",
                                 "function", "do", "and", "to"]
              , caseSensitive = False
              }

TokenParser{ parens = m_parens
           , braces = m_braces
           , brackets = m_brackets
           , identifier = m_identifier
           , natural = m_natural
           , integer = m_integer
           , reservedOp = m_reservedOp
           , reserved = m_reserved
           , commaSep1 = m_commaSep1
           , semiSep1 = m_semiSep1
           , whiteSpace = m_whiteSpace } = makeTokenParser def

fvalue = do
  f <- m_identifier
  args <- many (m_brackets expr)
  return $ FValue f args

m_reservedOp' name = try (string name >> m_whiteSpace)

expr :: Parser Expr
expr = buildExpressionParser table term <?> "expression"
table = [ [ Prefix (m_reservedOp "-" >> return (Neg)) ],
          [ Infix (m_reservedOp' "*" >> return (Op Mul)) AssocLeft
          , Infix (m_reservedOp' "/" >> return (Op Div)) AssocLeft
          ]
        , [ Infix (m_reservedOp' "+" >> return (Op Add)) AssocLeft
          , Infix (m_reservedOp' "-" >> return (Op Sub)) AssocLeft
          ]
        ]
term = m_parens expr
       <|> fmap (Num . fromInteger) m_integer
       <|> (do
        f <- m_identifier
        args <- many (m_brackets expr)
        return $ FValue f args
        )

function :: Parser [Rational]
function = do { m_reserved "function"
              ; m_reserved "of"
              ; n <- m_natural
              ; m_reservedOp ":"
              ; es <- m_commaSep1 expr
              ; return $ map (eval M.empty) es
              }
      <|>  do { e <- expr
              ; return [eval M.empty e]
              }

assign = do
  m_reserved "assign"
  ans <- sepBy1 (do
    e <- expr
    m_reserved "to"
    v <- m_identifier
    return (v, e)
    ) (m_reserved "and")
  m_reservedOp "!"
  return ans

intuitive :: Parser [Stmt]
intuitive = m_whiteSpace >> stmts <* eof
    where
      stmts :: Parser [Stmt]
      --stmt = m_semiSep1 stmt' -- newline
      stmts = (do
        s <- stmt
        ss <- stmts
        return $ s : ss) <|> return []
      stmt = do { v <- m_identifier
                 ; m_reserved "is"
                 ; f <- function
                 ; m_reservedOp "."
                 ; return (v := f)
                 }
          <|> fmap (Do (Num 1)) assign
          <|> do { m_reserved "do"
                 ; n <- m_braces expr
                 ; a <- assign
                 ; return $ Do n a
                 }
          <|> do { m_reserved "what"
                 ; m_reserved "is"
                 ; ans <- sepBy1 (do
                   v <- m_identifier
                   as <- many (m_brackets expr)
                   return (v, as)
                   ) (m_reserved "and")
                 ; m_reservedOp "?"
                 ; return $ What ans
                 }

data Value = Number Rational | Function [Rational] -- deriving Show
showr r = show (numerator r) ++
  if denominator r > 1 then "/" ++ show (denominator r) else ""
showrs rs = concat $ intersperse ", " $ map showr rs
type Env = M.Map String Value

eval :: Env -> Expr -> Rational
eval _ (Num r) = r
eval env (Neg e) = - eval env e
eval env (Op op e1 e2) = let
  v1 = eval env e1
  v2 = eval env e2
  in (case op of Add -> (+); Sub -> (-); Mul -> (*); Div -> (/)) v1 v2
eval env (FValue f es) = let
  Just v = M.lookup f env
  rs = map (eval env) es
  in case v of
    Number r -> r
    Function cs -> helper cs rs where
      helper [c] [] = c
      helper (c:cs) (r:rs) = c * r + helper cs rs

exec :: Stmt -> S.State Env ([String])
exec (f := v) = do
  env <- S.get
  S.put $ M.insert f (Function v) env
  return []
exec (Do n' ses) = do
  env <- S.get
  let n = fromInteger $ numerator (eval env n')
  S.replicateM_ n $ do
    S.forM_ ses $ \(v, e) -> do
      env <- S.get
      S.put $ M.insert v (Number $ eval env e) env
    return []
  return []
exec (What vs) = S.forM vs $ \(f, es) -> do
  env <- S.get
  let rs = map (eval env) es
  let Just res = M.lookup f env
  return $ case res of
    Number r -> showr r
    Function cs -> showrs $ app cs rs

app cs rs = helper 0 cs rs where
  helper s cs [] = init cs ++ [last cs + s]
  helper s (c:cs) (r:rs) = helper (s + c * r) cs rs

main = do
  prog <- getContents
  case parse intuitive "" prog of
    Right ss -> S.forM_ (S.evalState (mapM exec ss) M.empty) $ \ss -> do
      mapM_ putStrLn ss
    Left err -> print err
    
