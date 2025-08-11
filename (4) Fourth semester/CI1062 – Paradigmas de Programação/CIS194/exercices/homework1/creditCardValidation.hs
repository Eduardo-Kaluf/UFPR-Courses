{-# OPTIONS_GHC -Wall #-}

validCardNumbers :: [Int]
validCardNumbers = [49927398716, 1388]

invalidCardNumbers :: [Int]
invalidCardNumbers = [12345, 1386, 8675309, 79927398710]

toDigitsRev :: Int -> [Int]
toDigitsRev 0 = []
toDigitsRev n
    | n < 0     = []
    | otherwise =  [n `mod` 10] ++ toDigitsRev (n `div` 10)

doubleEveryTwo :: [Int] -> [Int]
doubleEveryTwo [] = [] 
doubleEveryTwo (x:[]) = [x] 
doubleEveryTwo (x:(y):(zs)) = x : y*2 : doubleEveryTwo zs 

sumDigits :: [Int] -> Int
sumDigits [] = 0
sumDigits (x:[]) = x
sumDigits (x:(xs))
    | x >= 10   = (x `div` 10) + (x `mod` 10) + sumDigits(xs)
    | otherwise = x + sumDigits(xs)

validateUnit :: Int -> Bool
validateUnit n = (sumDigits (doubleEveryTwo (toDigitsRev n))) `mod` 10 == 0

validateList :: [Int] -> [Bool]
validateList [] = []
validateList [x] = [validateUnit x]
validateList (x:(xs)) = [validateUnit x] ++ validateList xs

main :: IO ()
main = do
    print (validateList validCardNumbers)
    print (validateList invalidCardNumbers)
