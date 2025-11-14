module Main where


removeK :: [Int] -> Int -> [Int]
removeK [] _ = []
removeK (h:t) k
    | k == 1 = removeK t (k-1)
    | otherwise = h : removeK t (k-1)

between :: [Int] -> Int -> Int -> [Int]
between [] _ _ = []
between (h:t) i j
    | condition = h : between t (i-1) (j-1)
    | otherwise = between t (i-1) (j-1)
    where
        condition = ((i <= 1) && (j >= 1))

intercalate :: [Int] -> [Int] -> [Int]
intercalate [] [] = []
intercalate (h:t) [] = h : intercalate t []
intercalate [] (h:t) = h : intercalate [] t
intercalate (h:t) (hh:tt)
    | h < hh = h : intercalate t (hh:tt)
    | otherwise = hh : intercalate (h:t) tt


compareFunc :: Int -> Int -> Bool
compareFunc e x
    | condition = True
    | otherwise = False
    where
        condition = ((e >= x) && (e <= (x * x)))


filterFunc :: (Int -> Int -> Bool) -> [Int] -> Int -> [Int]
filterFunc _ [] _ = []
filterFunc f (h:t) x
    | condition = h : filterFunc f t x
    | otherwise = filterFunc f t x
    where
        condition = f h x


main :: IO ()
main = do
    putStrLn (show (removeK [1, 2, 3, 4] 2))
    putStrLn (show (between [1, 2, 3, 4, 5, 6] 2 4))
    putStrLn (show (intercalate [1, 2, 3, 7, 9] [4, 5, 6, 8, 10]))
    putStrLn (show (filterFunc compareFunc [1, 2, 3, 7, 9] 2 ))
