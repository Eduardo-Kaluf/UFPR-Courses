module Main where


main :: IO ()
main = do
    putStrLn (show ([x | x <- [0..15], mod x 3 == 0]))
    putStrLn (show ([[x] | x <- [1..5]]))
