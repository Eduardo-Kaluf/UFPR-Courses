module Main where

fourDimensionalTuple :: Int -> (Int, Int, Int, Int)
fourDimensionalTuple x = (x * 2, x * 3, x * 4, x * 5)

divisionEvenTuple :: Int -> (Int, String)
divisionEvenTuple x 
    | mod x 2 == 0 = (div x 2, "EVEN")
    | otherwise = (div x 2, "ODD")

sumMultEvenOdd :: [Int] -> (Int, Int)
sumMultEvenOdd [] = (0, 1)
sumMultEvenOdd (h:t)
    | h < 0 = (evenSum, h * oddMult)
    | otherwise = (h + evenSum, oddMult)
    where
        (evenSum, oddMult) = sumMultEvenOdd t

type Grade     = Int
type PointName = String
type PointType = String

turism :: Int -> [(PointName, Grade, PointType)] -> [(PointName, Grade, PointType)]
turism _ [] = []
turism ref (h:t) 
    | (ty == "parque" || ty == "museu") && g > ref = h : turism ref t
    | otherwise = turism ref t
    where
        (_, g, ty) = h

main :: IO ()
main = do
    putStrLn (show (fourDimensionalTuple 10))
    putStrLn (show (divisionEvenTuple 11))
    putStrLn (show (sumMultEvenOdd [1, 2, 3, 4, 5, -3, -4, -1]))
    putStrLn (show (turism 6 [("Rua 24 Horas", 5, "rua"), ("Tangua", 10, "parque"), ("MON", 7, "museu"), ("Mercado Municipal", 8, "mercado"), ("Jardim Botanico", 10, "parque"), ("Museu Paranaense", 6, "museu"), ("Feira do Largo da ordem", 9, "feira"), ("Barigui", 10, "parque"), ("Rua das Flores", 7, "rua") ]))