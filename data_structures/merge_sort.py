def merge(arr, l, m, r): 
    n1 = m - l + 1
    n2 = r- m 
  
  
    L = [0] * (n1) 
    R = [0] * (n2) 
  
    
    for i in range(0 , n1): 
        L[i] = arr[l + i] 
  
    for j in range(0 , n2): 
        R[j] = arr[m + 1 + j] 
  
   
    i = 0     # Initial index of first subarray 
    j = 0     # Initial index of second subarray 
    k = l     # Initial index of merged subarray 
  
    while i < n1 and j < n2 : 
        if L[i] <= R[j]: 
            arr[k] = L[i] 
            i += 1
        else: 
            arr[k] = R[j] 
            j += 1
        k += 1
  
    
    while i < n1: 
        arr[k] = L[i] 
        i += 1
        k += 1
  
  
    while j < n2: 
        arr[k] = R[j] 
        j += 1
        k += 1
  
