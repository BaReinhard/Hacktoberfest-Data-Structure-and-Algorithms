def bubbleSort(arr): 
    n = len(arr) 
    for i in range(n): 
        swapped = False
  
         
        for j in range(0, n-i-1): 
            if arr[j] > arr[j+1] : 
                arr[j], arr[j+1] = arr[j+1], arr[j] 
                swapped = True
  
        if swapped == False: 
            break
           
arr = [49, 74, 17, 38, 26, 16, 89] 
   
bubbleSort(arr) 
   
print ("Sorted array :") 
for i in range(len(arr)): 
    print ("%d" %arr[i],end=" ") 
  
