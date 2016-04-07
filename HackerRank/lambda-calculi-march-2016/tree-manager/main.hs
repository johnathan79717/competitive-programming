import Control.Monad
import Debug.Trace
import Prelude hiding (readList)

{-readLine = liftM read getLine-}
{-readList = liftM (map read . words) getLine-}

data Crumb = Crumb { rank :: Int, parentValue :: Int, siblings :: [Tree] } deriving Show
data Tree = Tree { value :: Int, children :: [Tree] } deriving Show
data Position = Position { tree :: Tree, crumbs :: [Crumb] } deriving Show
root = Position { tree = Tree { value = 0, children = []}, crumbs = [] }

main = do
    (_:inputs) <- liftM lines getContents
    foldM (\pos input -> do
        {-print pos-}
        let
            args = words input
            Position { tree = t, crumbs = crs } = pos
            Tree { value = v, children = ch } = t

        {-print args-}
        case head args of
            "change" -> let x = read $ args !! 1 in
                return Position { tree = Tree { value = x, children = ch }, crumbs = crs }
            "print" -> do
                print v
                return pos
            "visit" -> return $ if args !! 1 == "child" then
                    let n = read (args !! 2) - 1
                               in Position { tree = ch !! n
                                               , crumbs = Crumb { rank = n
                                                                , parentValue = v
                                                                , siblings = ch
                                                                } : crs
                                               }
                    else let
                        Crumb { rank = r, parentValue = p, siblings = s } = head crs
                        (a, b) = splitAt r s
                        s' = a ++ (t : tail b)
                     in case args !! 1 of
                            "left" -> Position { tree = s' !! (r - 1)
                                               , crumbs = Crumb { rank = r - 1
                                                                , parentValue = p
                                                                , siblings = s'
                                                                } : tail crs
                                               }
                            "right" -> Position { tree = s' !! (r + 1)
                                                , crumbs = Crumb { rank = r + 1
                                                                 , parentValue = p
                                                                 , siblings = s'
                                                                 } : tail crs
                                                }
                            "parent" -> Position { tree = Tree { value = p
                                                              , children = s'
                                                              }
                                                , crumbs = tail crs
                                                }
            "insert" -> return $
                let child = Tree { value = read $ args !! 2, children = [] } in
                    if args !! 1 == "child" then
                        Position { tree = Tree { value = v
                                               , children = child : ch
                                               }
                                 , crumbs = crs
                                 }
                        else let Crumb { rank = r, parentValue = p, siblings = s } = head crs
                           in case args !! 1 of
                              "left" -> let (a, b) = splitAt r s in
                                             {-traceShow (a, b) $-}
                                         Position { tree = t
                                                  , crumbs = Crumb { rank = r + 1
                                                                   , parentValue = p
                                                                   , siblings = a ++ (child : b)
                                                                   } : tail crs
                                                  }
                              "right" -> let (a, b) = splitAt (r+1) s in
                                        Position { tree = t
                                                 , crumbs = Crumb { rank = r
                                                                  , parentValue = p
                                                                  , siblings = a ++ (child : b) 
                                                                  } : tail crs
                                                 }

            "delete" -> let
                Crumb { rank = r, parentValue = p, siblings = s } = head crs
                (a, _:b) = splitAt r s
                in return $ Position { tree = Tree { value = p
                                                   , children = a ++ b
                                                   }
                                              , crumbs = tail crs
                                              }
        ) root inputs 
