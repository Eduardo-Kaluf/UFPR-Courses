module Main where


squareSum1 :: Int -> Int -> Int -> Int
squareSum1 x y z = (x * x) + (y * y) + (z * z)

squareSum2 :: Float -> Float -> Float -> Float
squareSum2 x y z = (x ** 2.0) + (y ** 2.0) + (z ** 2.0)

-- this one is just works for integers, does not work for floats
squareSum3 :: Int -> Int -> Int -> Int
squareSum3 x y z = (x ^ 2) + (y ^ 2) + (z ^ 2)

isEven1 :: Int -> Bool
isEven1 x
  | (mod x 2) == 0 = True
  | otherwise = False

isEven2 :: Int -> Bool
isEven2 x = even x


main :: IO ()
main = do
    putStrLn (show (squareSum1 2 3 4))
    putStrLn (show (squareSum2 2.0 3.0 4.0))
    putStrLn (show (squareSum3 2 3 4))
    putStrLn (show (isEven1 4))
    putStrLn (show (isEven2 3))