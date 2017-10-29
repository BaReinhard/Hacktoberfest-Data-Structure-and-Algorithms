from array import *

#Counts single digit numbers
def count_sort(arr):
   print("Sorting..")
   print(arr)
   countArray = [0 for x in range (10)]

   #count the numbers in the array 
   for num in arr:
     countArray[num] = countArray[num] + 1

   prev = 0
   
   #Find the starting index for each number
   for i in range (10):
     countArray[i] = prev + countArray[i]
     prev = countArray[i]   

   #Initialize return array
   output = [None] * len(arr)
 
   #For each number, try to place it on the starting index. If already assigned,
   #Decrement by 1 until we find an available index
   for num in arr:
     numIndex = countArray[num] - 1
     while (output[numIndex] is not None): 
       numIndex = numIndex - 1
     output[numIndex] = num

 
   return output


print(count_sort([9,8,7,6,5,4,3,2,1]))     
print(count_sort([1,3,3,2,3,5,7,5,6,7,8,0,9]))     
