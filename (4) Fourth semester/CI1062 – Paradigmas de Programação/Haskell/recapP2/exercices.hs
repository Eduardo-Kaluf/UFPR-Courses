module Main where

imc :: Double -> Double -> String
imc p a
    | calc < 18.5 = "Below"
    | calc < 25.0 = "Normal"
    | calc < 30.0 = "Over"
    | otherwise   = "Obese"
    where
        calc = p / (a * a)

imcIf :: Double -> Double -> String
imcIf p a = if calc < 18.5 then "Below"
       else if calc < 25.0 then "Normal"
       else if calc < 30.0 then "Over"
       else "Obese"
       where
        calc = p / (a * a)

compact :: [Int] -> [Int]
compact [] = []
compact [x] = [x]
compact (x:y:t)
    | x == y = compact (y:t)
    | otherwise = x : compact (y:t)

reverseList :: [Int] -> [Int]
reverseList [] = []
reverseList (h:t) = reverseList t ++ [h]

mergeList :: [Int] -> [Int] -> [Int]
mergeList [] [] = []
mergeList [] (x:t) = (x:t)
mergeList (x:t) [] = (x:t)
mergeList (h:t) (x:y)
    | h < x = h : mergeList t (x:y)
    | otherwise = x : mergeList (h:t) y

quickSort :: [Int] -> [Int]
quickSort [] = []
quickSort [x] = [x]
quickSort (h:t) = quickSort left ++ [h] ++ quickSort right
    where
        left  = [x | x <- t, x < h]
        right = [y | y <- t, y >= h]

myLookUp :: Int -> [(Int, String)] -> String
myLookUp _ [] = "Null"
myLookUp x (h:t)
    | x == key = val
    | otherwise = myLookUp x t
    where
        (key, val) = h

myUnzip :: [(Int, String)] -> ([Int], [String])
myUnzip [] = ([], [])
myUnzip (h:t) = (num : integers, word : strings)
    where
        (num, word) = h
        (integers, strings) = myUnzip t

totalValue :: [(String, Int, Float)] -> Float
totalValue [] = 0.0
totalValue (h:t) = price + totalValue t
    where
        (_, q, p) = h
        price = (fromIntegral q) * p

myZip :: [Int] -> [Int] -> [(Int, Int)]
myZip [] _ = []
myZip _ [] = []
myZip (h:t) (x:y) = (h, x) : myZip t y

myMap :: (Int -> Int) -> [Int] -> [Int]
myMap _ [] = []
myMap f (h:t) = (f h) : (myMap f t)

myPartition :: (Int -> Bool) -> [Int] -> ([Int], [Int])
myPartition _ [] = ([], [])
myPartition f (h:t)
    | condition = (h:trues, falses)
    | otherwise = (trues, h:falses)
    where
        condition = (f h) == True
        (trues, falses) = myPartition f t

myLength :: [Int] -> Int
myLength [] = 0
myLength (h:t) = 1 + myLength t


main :: IO ()
main = do
    putStrLn (show (imc 10.9 1.87))
    putStrLn (show (imcIf 10.9 1.87))
    putStrLn (show (compact [1, 1, 2, 3, 3, 3, 1]))
    putStrLn (show (reverseList [1, 2, 3, 4, 5, 6]))
    putStrLn (show (mergeList [1, 2, 3, 13, 15, 59] [7, 9, 12, 45]))
    putStrLn (show ([x*x | x <- [0..10]]))
    putStrLn (show ([x | x <- [0..50], mod x 2 == 1]))
    putStrLn (show ([y | x <- [[1, 2, 3], [4, 5, 6], [7, 8, 9]], y <- x]))
    putStrLn (show ([head x | x <- ["Ana", "Bruno", "Carla", "Daniel"]]))
    putStrLn (show ([(x, y) | x <- ['A', 'B'], y <- [1, 2, 3]]))
    putStrLn (show (quickSort [99, 6, 3, 2, 15, 59, 7, 9, 1, 45]))
    putStrLn (show (myLookUp 2 [(1, "Ana"), (2, "Bruno"), (3, "Carla")]))
    putStrLn (show (myUnzip [(1, "Ana"), (2, "Bruno"), (3, "Carla")]))
    putStrLn (show (totalValue [("Maçã", 10, 0.5), ("Banana", 5, 0.8), ("Laranja", 20, 0.3)]))
    putStrLn (show (myZip [1, 2, 3, 13, 15, 59] [7, 9, 12, 45]))
    putStrLn (show (myMap (*10) [7, 9, 12, 45]))
    putStrLn (show (myPartition (>3) [7, 9, 1, 3, 9, 728]))
    putStrLn (show (myLength [7, 9, 1, 3, 9, 728]))
