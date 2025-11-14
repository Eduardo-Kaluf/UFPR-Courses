module Main where

type FirstName = String
type Title = String
type Gender = Char

getFirstName :: (FirstName, Title, Gender) -> FirstName
getFirstName (fn, _, _) = fn

getTitle :: (FirstName, Title, Gender) -> Title
getTitle (_, sr, _) = sr

getGender :: (FirstName, Title, Gender) -> Gender
getGender (_, _, g) = g


base :: Int -> (String, String, Char)
base x
    |x == 1 = ("joao", "mestre", 'm')
    |x == 2 = ("jonas", "doutor", 'm')
    |x == 3 = ("joice", "mestre", 'f')
    |x == 4 = ("janete", "doutor", 'f')
    |x == 5 = ("jocileide", "doutor", 'f')
    |otherwise = ("ninguem", "x", 'x')

contMestre :: Int -> Gender -> Int
contMestre 0 _ = 0
contMestre x g
    | t == "mestre" && g == tg = 1 + contMestre (x-1) g
    | otherwise = contMestre (x-1) g
    where 
        teacher = base x
        t = getTitle  teacher
        tg = getGender teacher   


contDoutor :: Int -> Gender -> Int
contDoutor 0 _ = 0
contDoutor x g
    | t == "doutor" && g == tg = 1 + contDoutor (x-1) g
    | otherwise = contDoutor (x-1) g
    where
        teacher = base x
        t = getTitle  teacher
        tg = getGender teacher   

cont :: Title -> Gender -> Int
cont t g
    | t == "mestre" = contMestre 5 g
    | t == "doutor" = contDoutor 5 g


main :: IO ()
main = do
    putStrLn (show (cont "doutor" 'm'))
    putStrLn (show (cont "doutor" 'f'))
    putStrLn (show (cont "mestre" 'm'))
    putStrLn (show (cont "mestre" 'f'))
