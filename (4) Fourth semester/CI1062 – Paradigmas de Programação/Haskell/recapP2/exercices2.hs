module Main where

-- https://wiki.haskell.org/index.php?title=99_questions/21_to_28

insertAt :: a -> [a] -> Int -> [a]
insertAt x [] _ = [x]
insertAt x (h:t) i
    | i == 1 = x : h : t
    | otherwise = h : insertAt x t (i-1)

range :: Int -> Int -> [Int]
range a b = [x | x <- [a..b]]


myLength :: [a] -> Int
myLength [] = 0
myLength (h:t) = 1 + myLength t

lengthSort :: [[a]] -> [[a]]
lengthSort [] = []
lengthSort [x] = [x]
lengthSort (h:t) = lengthSort left ++ [h] ++ lengthSort right
    where
        left =  [x | x <- t, myLength x < myLength h]
        right = [y | y <- t, myLength y >= myLength h]


auxReplicate :: a -> Int -> [a]
auxReplicate _ 0 = []
auxReplicate a x = a : auxReplicate a (x-1)

myReplicate :: [a] -> Int -> [a]
myReplicate [] _ = []
myReplicate (h:t) x = auxReplicate h x ++ myReplicate t x

split :: [a] -> Int -> ([a], [a])
split [] _ = ([], [])
split (h:t) x
    | x == 0    = ([], h:t)
    | otherwise = (h : first, second)
    where
        (first, second) = split t (x-1)

approved :: [(String, Int)] -> Int -> [String]
approved [] _ = []
approved (h:t) x
    | above_mark = student_name : others
    | otherwise  = others
    where
        (student_name, grade) = h
        above_mark = grade >= x
        others = approved t x

distance :: (Double, Double) -> Double
distance (x, y) = x * x + y * y

closestOrigin :: [(Double, Double)] -> (Double, Double)
closestOrigin [] = (1000, 1000) -- Out of bounds
closestOrigin [(x,y)] = (x,y)
closestOrigin (h:t)
    | distance h < distance nextPoint = h
    | otherwise = nextPoint
    where
        nextPoint = closestOrigin t

filterList :: [Int] -> (Int -> Bool) -> [Int]
filterList [] _ = []
filterList (h:t) f
    | f h == True = h : filterList t f
    | otherwise   = filterList t f


main :: IO ()
main = do
    putStrLn (show (insertAt 7 [1, 2, 3, 4] 2))
    putStrLn (show (range 2 8))
    putStrLn (show (lengthSort ["abc", "de", "fgh", "de", "ijkl", "mn", "o"]))
    putStrLn (show (myReplicate "abc" 3))
    putStrLn (show (split "abcdefg" 3))
    putStrLn (show (approved [("Ana", 7), ("Bruno", 4), ("Carla", 9), ("Daniel", 6)] 7))
    putStrLn (show (closestOrigin [(1.0, 5.0), (0.5, 1.0), (10.0, 10.0), (2.0, 2.0)]))
    putStrLn (show (filterList [1, 2, 3, 4, 5] (>3)))
