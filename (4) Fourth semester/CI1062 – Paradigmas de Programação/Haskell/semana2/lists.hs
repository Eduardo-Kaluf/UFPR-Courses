module Main where


sumList :: [Int] -> Int
sumList [] = 0
sumList (h:t) = h + sumList t

removeEven :: [Int] -> [Int]
removeEven [] = []
removeEven (h:t)
    | mod h 2 == 0 = removeEven t
    | otherwise = h : removeEven t

invertList :: [Float] -> [Float]
invertList [] = []
invertList (h:t) = invertList t ++ [h]


namesWithA :: [String] -> [String]
namesWithA [] = []
namesWithA (h:t)
    | head h == 'A' = [h] ++ namesWithA t
    | otherwise = namesWithA t


main :: IO ()
main = do
    putStrLn (show (sumList [0 .. 10]))
    putStrLn (show (removeEven [0 .. 10]))
    putStrLn (show (invertList [1.0, 2.0, 3.4, 3.14, 7.0]))
    putStrLn (show (namesWithA ["Ana", "America", "Shima"]))
