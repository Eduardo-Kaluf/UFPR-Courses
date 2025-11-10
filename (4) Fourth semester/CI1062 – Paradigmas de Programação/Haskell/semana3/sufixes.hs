module Main where

type Name = String

addSr :: Name -> Name
addSr n = "Sr. " ++ n

addSra :: Name -> Name
addSra n = "Sra. " ++ n

addSrta :: Name -> Name
addSrta n = "Srta. " ++ n

mapSufix :: [Name] -> (Name -> Name) -> [Name]
mapSufix [] _ = []
mapSufix names func = func h : mapSufix t func
    where
        (h:t) = names

main :: IO ()
main = do
    putStrLn (show (mapSufix ["Sergio", "Shima", "Kaluf"] addSr))
    putStrLn (show (mapSufix ["Sergio", "Shima", "Kaluf"] addSra))
    putStrLn (show (mapSufix ["Sergio", "Shima", "Kaluf"] addSrta))
