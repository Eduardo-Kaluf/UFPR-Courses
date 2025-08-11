{-# OPTIONS_GHC -Wall #-}
module Main where
import Log

parseMessage :: String -> LogMessage
parseMessage input = case words input of
                        ("I" : time : strings)     ->  LogMessage Info (read time :: Int) (unwords strings)
                        ("W" : time : strings)     ->  LogMessage Warning (read time :: Int) (unwords strings)
                        ("E" : e : time : strings) ->  LogMessage (Error (read e :: Int)) (read time :: Int) (unwords strings)
                        (strings) -> Unknown (unwords strings)

parse :: String -> [LogMessage]
parse input = map parseMessage (lines input)

-------

getTime :: LogMessage -> Int
getTime (LogMessage _ time _) = time
getTime (Unknown _)           = 0

insert :: LogMessage -> MessageTree -> MessageTree
insert (Unknown _) msgTree = msgTree
insert newMsg Leaf = Node Leaf newMsg Leaf
insert newMsg (Node left existingMsg right)
    | getTime newMsg >= getTime existingMsg = Node left existingMsg (insert newMsg right)
    | getTime newMsg < getTime existingMsg = Node (insert newMsg left) existingMsg right

build :: [LogMessage] -> MessageTree
build [] = Leaf
build (x:xs) = insert x (build(xs))

inOrder :: MessageTree -> [LogMessage]
inOrder Leaf = []
inOrder (Node left existingMsg right) = inOrder(left) ++ [existingMsg] ++ inOrder(right)

-------

whatWentWrong :: [LogMessage] -> [String]
whatWentWrong logList = 
        let sortedMessages = inOrder (build logList)
        in extractErrors sortedMessages
    where
        extractErrors :: [LogMessage] -> [String]
        extractErrors [] = []
        extractErrors (x@(LogMessage (Error val) _ _) : xs)
            | val >= 50 = [show x] ++ extractErrors xs
        extractErrors (_ : xs) = extractErrors xs

main :: IO ()   
main = do
    logMessages <- testParse parse 1000 "error.log"
    putStrLn "--- First 1000 Parsed Messages ---"
    putStrLn (unlines (map show logMessages))

    putStrLn "\n--- Test with inline sample data ---"
    let sampleErrors = whatWentWrong (parse ("I 6 Completed armadillo processing\nI 1 Nothing to report\nI 4 Everything normal\nI 11 Initiating self-destruct sequence\nE 70 3 Way too many pickles\nE 65 8 Bad pickle-flange interaction detected\nW 5 Flange is due for a check-up\nI 7 Out for lunch, back in two time steps\nE 20 2 Too many pickles\nI 9 Back from lunch\nE 99 10 Flange failed!"))
    putStrLn (unlines sampleErrors)

    putStrLn "\n--- All Severe Error Messages from file ---"
    errorStrings <- testWhatWentWrong parse whatWentWrong "error.log"
    putStrLn (unlines errorStrings)
