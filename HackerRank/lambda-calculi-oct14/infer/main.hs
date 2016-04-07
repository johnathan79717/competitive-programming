import Control.Applicative((<*))
import Text.Parsec
import Text.Parsec.String
import Text.Parsec.Expr
import Text.Parsec.Token
import Text.Parsec.Language
import Debug.Trace
import Data.Ratio
import Data.List
import qualified Control.Monad.State as S

data Expr = Let String Expr Expr | App Expr [Expr] | Abs [String] Expr | Var String deriving Show

def = emptyDef{ commentStart = ""
              , commentEnd = ""
              , identStart = letter <|> char '_'
              , identLetter = alphaNum <|> char '_'
              , opStart = oneOf "=-"
              , opLetter = oneOf "=->"
              , reservedOpNames = ["=", "->"]
              , reservedNames = ["let", "in", "fun", "forall"]
              , caseSensitive = True
              }

TokenParser{ parens = m_parens
           , braces = m_braces
           , brackets = m_brackets
           , identifier = m_identifier
           , reservedOp = m_reservedOp
           , reserved = m_reserved
           , commaSep = m_commaSep
           , whiteSpace = m_whiteSpace } = makeTokenParser def

m_reservedOp' name = try (string name >> m_whiteSpace)

expr :: Parser Expr
expr = do
	m_reserved "let"
	x <- m_identifier
	m_reservedOp "="
	e1 <- expr
	m_reserved "in"
	e2 <- expr
	return $ Let x e1 e2
  <|> do
  	m_reserved "fun"
  	argList <- many m_identifier
  	m_reservedOp "->"
  	e <- expr
  	return $ Abs argList e
  <|> do
  	e <- simpleExpr
  	pls <- many $ m_parens $ m_commaSep expr
  	return $ foldl App e pls

simpleExpr =
	m_parens expr
  <|> do
	x <- m_identifier
	return $ Var x

data Type = Fun [Type] Type | 

infer :: Expr -> State (Env, Int) Type
infer (Var x) = 
infer ()

main = do
  prog <- getLine
  case parse expr "" prog of
    Right ss -> print ss
    Left err -> print err
    
