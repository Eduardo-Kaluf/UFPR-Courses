module Main where

isPositive :: Float -> Bool
isPositive x
    | x > 0.0 = True
    | otherwise = False

isNegative :: Float -> Bool
isNegative x
    | x < 0.0 = True
    | otherwise = False

isZero :: Float -> Bool
isZero x
    | x == 0.0 = True
    | otherwise = False

filterNumList :: [Float] -> (Float -> Bool) -> [Float]
filterNumList [] _ = []
filterNumList nums func
    | func h == True = h : filterNumList t func
    | otherwise = filterNumList t func
    where
        (h:t) = nums

main :: IO ()
main = do
    putStrLn (show (filterNumList [2.0, -7.0, 0.0] isPositive))
    putStrLn (show (filterNumList [2.0, -7.0, 0.0] isNegative))
    putStrLn (show (filterNumList [2.0, -7.0, 0.0] isZero))
