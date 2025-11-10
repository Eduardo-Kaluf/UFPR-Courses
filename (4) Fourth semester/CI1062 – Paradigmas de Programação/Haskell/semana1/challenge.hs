module Main where

dataBase :: Int -> Float
dataBase 1 = 5.0
dataBase 2 = 10.0
dataBase 3 = 12.0
dataBase 4 = 3.0
dataBase 5 = 5.0
dataBase _ = 0.0

sumDataBase :: Int -> Float
sumDataBase 0 = 0
sumDataBase x = dataBase x + sumDataBase (x - 1)

meanDataBase :: Int -> Float
meanDataBase x = (sumDataBase x) / (fromIntegral x)

main :: IO ()
main = do
    putStrLn (show (meanDataBase 5))
