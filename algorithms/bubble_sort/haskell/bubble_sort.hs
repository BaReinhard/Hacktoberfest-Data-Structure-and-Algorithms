import Debug.Trace

main :: IO()
main = do
  let sorted = bubbleSort [6, 5, 3, 1, 8, 7, 2, 4] :: [Integer]
  print sorted

bubbleSort :: (Ord a, Show a) => [a] -> [a]
--bubbleSort lst | trace ("sorting: " ++ show lst) False = undefined
bubbleSort [] = []
bubbleSort [x] = [x]
bubbleSort (x:y:rest) =
  bubbleSort (init bubbled) ++ [last bubbled]
  where
    (first, second) = if x > y then (y,x) else (x,y)
    bubbled = first : bubbleSort (second:rest)
