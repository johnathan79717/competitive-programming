data Section = Section { getA :: Int, getB :: Int, getC :: Int } deriving (Show)
type RoadSystem = [Section]

heathrowToLondon :: RoadSystem  
heathrowToLondon = [Section 50 10 30, Section 5 90 20, Section 40 2 25, Section 10 8 0]  

data Label = A | B | C deriving (Show)  
type Path = [(Label, Int)]

roadStep :: (Path, Path) -> Section -> (Path, Path)
roadStep (pathA, pathB) (Section a, b, c)
  | a + c < b   = (pathA ++ [(A, a)]        , pathA ++ [(A, a), (C, c)] )
  | b + c < a   = (pathB ++ [(B, b), (C, c)], pathB ++ [(B, b)]         )
  | otherwise   = (pathA ++ [(A, a)]        , pathB ++ [(B, b)]         )