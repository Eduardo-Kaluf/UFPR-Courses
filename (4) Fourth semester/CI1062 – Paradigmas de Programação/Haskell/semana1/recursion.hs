module Main where

fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib x = fib (x - 1) + fib (x - 2)

numOfDigits :: Int -> Int
numOfDigits 0 = 0
numOfDigits x = 1 + numOfDigits ((x - (mod x 10)) `div` 10)

sumOfDigits :: Int -> Int
sumOfDigits 0 = 0
sumOfDigits x = (mod x 10) + numOfDigits ((x - (mod x 10)) `div` 10)

main :: IO ()
main = do
    putStrLn (show (fib 8))
    putStrLn (show (numOfDigits 112423))
    putStrLn (show (sumOfDigits 111))
