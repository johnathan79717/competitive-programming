import Control.Applicative((<*))
import Text.Parsec
import Text.Parsec.String
import Text.Parsec.Expr
import Text.Parsec.Token
import Text.Parsec.Language
import Debug.Trace
import Data.Ratio
import Data.List

newtype Z = Z Integer
instance Show Z where
  show (Z i) = show i
data Expr = Neg Expr | Add Expr Expr | Sub Expr Expr | Mul Expr Expr | Div Expr Expr | Num Z deriving Show

p = 1000000007
instance Num Z where
  Z x + Z y = if x + y < p then Z (x + y) else Z (x + y - p)
  Z x - Z y = if x - y < 0 then Z (x - y + p) else Z (x - y)
  Z x * Z y = Z (x * y `mod` p)

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

m_reservedOp' name = try (string name >> m_whiteSpace)

expr :: Parser Z
--expr = buildExpressionParser etable factor <?> "expression"
expr = buildExpressionParser etable term <?> "expression"
etable = [[ Infix (m_reservedOp' "+" >> return (+)) AssocRight
          , Infix (m_reservedOp' "-" >> return (-)) AssocRight
          ]
        ]

term :: Parser Z
term = buildExpressionParser ttable factor <?> "term"
ttable = [[ Infix (m_reservedOp' "*" >> return (*)) AssocRight
          , Infix (m_reservedOp' "/" >> return (div')) AssocRight
          ]
        ]

factor :: Parser Z
factor = fmap (Z) m_natural
      <|> m_parens expr
      <|> (buildExpressionParser ftable factor <?> "expression")
ftable = [[ Prefix (m_reservedOp "-" >> return (Z 0 -))
          , Prefix (m_reservedOp "+" >> return id)
          ]
        ]

div' a b = a * (b ^ (p-2))

main = do
  prog <- getLine
  case parse expr "" prog of
    Right ss -> print ss
    Left err -> print err
    
