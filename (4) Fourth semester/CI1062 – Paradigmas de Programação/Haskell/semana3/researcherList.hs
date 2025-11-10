module Main where

type FirstName = String
type Title = String
type Gender = Char
type Researcher = (FirstName, Title, Gender)
type Group = [Researcher]

getFirstName :: Researcher -> FirstName
getFirstName (fn, _, _) = fn

getTitle :: Researcher -> Title
getTitle (_, sr, _) = sr

getGender :: Researcher -> Gender
getGender (_, _, g) = g

base :: Int -> Researcher
base x
    |x == 1 = ("joao", "mestre", 'm')
    |x == 2 = ("jonas", "doutor", 'm')
    |x == 3 = ("joice", "mestre", 'f')
    |x == 4 = ("janete", "doutor", 'f')
    |x == 5 = ("jocileide", "doutor", 'f')
    |otherwise = ("ninguem", "x", 'x')

buildList :: Int -> Group
buildList 0 = [base 0]
buildList x = r : buildList (x - 1)
    where
        r = base x

doctorsList :: Group -> [FirstName]
doctorsList x = [fn | (fn, t, _) <- x, t == "doutor"]


main :: IO ()
main = do
    putStrLn (show (buildList 5))
    putStrLn (show (doctorsList (buildList 5)))
