main :: IO()
main = do
  let sorted = insertionSort [6, 5, 3, 1, 8, 7, 2, 4] :: [Integer]
  print sorted

insert :: Ord a => a -> [a] -> [a]
insert x [] = [x]
insert x (y:ys) | x < y     = x:y:ys
                | otherwise = y:(insert x ys)

insertionSort :: Ord a => [a] -> [a]
insertionSort [] = []
insertionSort (x:xs) = insert x (insertionSort xs)