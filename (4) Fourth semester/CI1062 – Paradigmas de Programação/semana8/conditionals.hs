module Main where

canDrink1 :: Int -> String
canDrink1 x = if x >= 18 then "Yes" else "No"

canDrink2 :: Int -> String
canDrink2 x
  | x >= 18 = "Yes"
  | otherwise = "No"

isGreaterThanZero1 :: Int -> String
isGreaterThanZero1 x = if x > 0 
    then "Greater Than Zero"
    else if x == 0 then "Equals Zero"
    else "Less Than Zero"

isGreaterThanZero2 :: Int -> String
isGreaterThanZero2 x
  | x > 0 = "Greater Than Zero"
  | x == 0 = "Equals Zero"
  | x < 0 = "Less Than Zero"

isLeapYear1 :: Int -> Bool
isLeapYear1 x = 
    if (mod x 4) == 0 && (mod x 100) /= 0 
        then True
    else if (mod x 400) == 0 
        then True 
    else False

isLeapYear2 :: Int -> Bool
isLeapYear2 x = 
    if div4 == 0 && div100 /= 0 
        then True
    else if div400 == 0 
        then True 
    else False
    
    where
        div4 = mod x 4
        div100 = mod x 100
        div400 = mod x 400


isLeapYear3 :: Int -> Bool
isLeapYear3 x
  | (mod x 4 == 0) && (mod x 100 /= 0) = True
  | (mod x 400 == 0) = True
  | otherwise = False


main :: IO ()
main = do
    putStrLn (show (canDrink1 18))
    putStrLn (show (canDrink2 16))
    putStrLn (show (isGreaterThanZero1 18))
    putStrLn (show (isGreaterThanZero2 (-2)))
    putStrLn (show (isGreaterThanZero2 0))
    putStrLn (show (isLeapYear1 4))
    putStrLn (show (isLeapYear2 100))
    putStrLn (show (isLeapYear3 43))