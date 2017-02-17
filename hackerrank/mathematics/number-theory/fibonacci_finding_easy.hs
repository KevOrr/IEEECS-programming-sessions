import Data.List.Split

fib :: Integer -> Integer
fib = (map fib_actual [0..] !!)
  where fib_actual 0 = 0
        fib_actual 1 = 1
        fib_actual n = fib_actual (n-1) + fib_actual (n-2)

main = do
  n_tests <- read $ getLine
  tests <- map (map read (splitOn " " .)) $ getContents
