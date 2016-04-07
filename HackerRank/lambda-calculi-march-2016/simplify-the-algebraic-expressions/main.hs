{-# LANGUAGE FlexibleInstances #-}
import Data.Ratio
import Prelude hiding ( (<*>) )
import Data.List
import Control.Applicative((<*))
import qualified Data.Map as M
import Control.Monad
import Text.Parsec
import Text.Parsec.String
import Text.Parsec.Expr
import Text.Parsec.Token
import Text.Parsec.Language
import Debug.Trace
import Data.Char

data Op = Add | Sub | Mul | Div | Pow deriving Show
data Exp = Op Op Exp Exp | Monomial Rational Integer deriving Show
{-data Stmt = String := Exp | If Exp Stmt Stmt | While Exp Stmt | Seq [Stmt] deriving Show-}

def :: LanguageDef st
def = emptyDef{ identStart = letter
              , identLetter = alphaNum
              , opStart = oneOf "+-*/><:"
              , opLetter = oneOf "+-*/><:="
              , reservedOpNames = ["+", "-", "*", "/"]
              , reservedNames = ["x"]
              }

TokenParser{ parens = m_parens
           , natural = m_natural
           , reservedOp = m_reservedOp
           , reserved = m_reserved
           , whiteSpace = m_whiteSpace } = makeTokenParser def

expr :: Parser Exp
expr = buildExpressionParser table terms <?> "expression"
table = [ [ Infix (m_reservedOp "^" >> return (Op Pow)) AssocLeft]
        , [ Infix (m_reservedOp "*" >> return (Op Mul)) AssocLeft
          , Infix (m_reservedOp "/" >> return (Op Div)) AssocLeft
          ]
        , [ Infix (m_reservedOp "+" >> return (Op Add)) AssocLeft
          , Infix (m_reservedOp "-" >> return (Op Sub)) AssocLeft
          ]
        ]

coefficient = do
    c <- m_natural
    return $ Monomial (fromInteger c) 0
mono = do
    m_reserved "x"
    p <- power
    return $ Monomial 1 p
{-mono0 = mono <|> return 0-}

power = 
    do
        m_reservedOp "^"
        p <- m_natural
        return $ fromInteger p
    <|> return 1

terms =
    do
        ts <- many1 term
        return $ foldl1 (Op Mul) ts
    <|> return (Monomial 0 0)
term = m_parens expr <|> coefficient <|> mono
    {-<|> do-}
        {-c <- coefficient-}
        {-p <- mono0-}
        {-return $ Monomial (fromInteger c) p-}
    {-<|> do-}
        {-p <- mono-}
        {-return $ Monomial 1 $ fromInteger p-}
    {-<|> return (Monomial 0 0)-}

parser = do
    m_whiteSpace
    e <- expr
    eof
    return e

newtype UPoly a = UP [a] deriving (Eq,Ord)

instance Show (UPoly Rational) where
    -- show (UP []) = "0"
    show (UP as) = showUP "x" as

showUP _ [] = "0"
showUP v as = let powers = reverse $ filter ( (/=0) . fst ) $ zip as [0..]
                  cs' = concatMap showTerm powers
               in case cs' of
                    "" -> "0"
                    _:c:_:cs -> if c == '+' then cs else c:cs
    where showTerm (a,i) = showCoeff a ++ showPower a i
          showCoeff a = case show $ numerator a of
                        "1" -> " + "
                        "-1" -> " - "
                        '-':cs -> " - " ++ cs
                        cs -> " + " ++ cs
          showPower a i | i == 0 = case show $ numerator a of
                                   "1" -> "1"
                                   "-1" -> "1"
                                   otherwise -> ""
                        | i == 1 = v -- "x"
                        | i > 1  = v ++ "^" ++ show i -- "x^" ++ show i

-- The fussiness of the code is to avoid adding trailing zeroes, eg [3] <+> [-3]
-- Otherwise we would have to normalise after every addition
as <+> [] = as
[] <+> bs = bs
-- (a:as) <+> (b:bs) = (a+b) : (as <+> bs)
(a:as) <+> (b:bs) = let c = a+b
                        cs = as <+> bs
                    in if c == 0 && null cs then [] else c:cs

-- The fussiness of the code is to avoid adding trailing zeroes.
-- Note that since we call <+>, we rely on it having similar properties.
[] <*> _ = []
_ <*> [] = [] -- to avoid [0,1] <*> [] -> [0]
(a:as) <*> bs = if null as then map (a*) bs else map (a*) bs <+> (0 : as <*> bs)

instance (Eq a, Num a) => Num (UPoly a) where
    UP as + UP bs = UP $ as <+> bs
    negate (UP as) = UP $ map negate as
    UP as * UP bs = UP $ as <*> bs
    fromInteger 0 = UP []
    fromInteger a = UP [fromInteger a]
    abs _ = error "Prelude.Num.abs: inappropriate abstraction"
    signum _ = error "Prelude.Num.signum: inappropriate abstraction"

eval (Monomial c p) = UP $ genericReplicate p 0 ++ [c]
eval (Op op e1 e2) = let x = eval e1
                         y = eval e2
                      in case op of
                           Add -> x + y
                           Sub -> x - y
                           Mul -> x * y
                           Div -> divUP x y
                           Pow -> let UP [a] = y in x ^ numerator a
-- DIVISION ALGORITHM

-- degree
deg (UP as) = length as

-- leading term
lt (UP as) = last as

monomial a i = UP $ replicate i 0 ++ [a]

-- quotRem for UPolys over a field
quotRemUP f g = qr 0 f where
    qr q r = if deg r < deg g
             then (q,r)
             else let s = monomial (lt_r / lt_g) (deg r - deg g)
                  in qr (q+s) (r-s*g)
                where
                    lt_r = lt r
                    lt_g = lt g

divUP f g = fst $ quotRemUP f g
modUP f g = snd $ quotRemUP f g                  

main = do
    n <- liftM read getLine
    replicateM_ n $ do
        str <- getLine
        {-either print (print) $ parse parser "" str-}
        {-either print (print . eval) $ parse parser "" str-}
        let Right r = parse parser "" str
        print $ eval r
