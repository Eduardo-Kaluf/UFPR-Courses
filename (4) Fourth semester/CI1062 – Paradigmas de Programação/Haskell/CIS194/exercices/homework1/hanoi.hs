type Peg = String
type Move = (Peg, Peg)

hanoi :: Integer -> Peg -> Peg -> Peg -> [Move]
hanoi 0 _ _ _ = []
hanoi n x y z = (hanoi (n - 1) x z y) ++ [(x, y)] ++ (hanoi (n - 1) z y x)

main :: IO ()
main = do
    print (hanoi 2 "a" "b" "c")
