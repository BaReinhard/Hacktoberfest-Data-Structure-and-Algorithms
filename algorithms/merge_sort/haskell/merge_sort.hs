module MergeSort where

{-
Merge Sort in Haskell.
-}

merge :: Ord a =>[a] -> [a] -> [a]
merge [] ys = ys
merge xs [] = xs
merge (x:xs) (y:ys)
  | x > y = y:x:(merge xs ys)
  | y >= x = x:y:(merge xs ys)

mergeSort' :: Ord a => Int -> [a] -> [a]
mergeSort' 1 [x]  = [x]
mergeSort' len xs = merge (mergeSort' middle left) (mergeSort' (len-middle) right)
  where
    middle = len `div` 2
    (left, right) = splitAt middle xs
    
mergeSort :: Ord a => [a] -> [a]
mergeSort [] = []
mergeSort [x] = [x]
mergeSort xs  = mergeSort' (length xs) xs
