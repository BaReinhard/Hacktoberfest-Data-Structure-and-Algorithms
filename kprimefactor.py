# A function to generate prime factors of a 
# given number n and return k-th prime factor 
def kPrimeFactor(n,k) : 
  
    # Find the number of 2's that divide k 
    while (n % 2 == 0) : 
        k = k - 1
        n = n / 2
        if (k == 0) : 
            return 2
   
    # n must be odd at this point. So we can  
    # skip one element (Note i = i +2) 
    i = 3
    while i <= math.sqrt(n) : 
      
        # While i divides n, store i and divide n 
        while (n % i == 0) : 
            if (k == 1) : 
                return i 
   
            k = k - 1
            n = n / i 
          
        i = i + 2
   
    # This condition is to handle the case  
    # where n is a prime number greater than 2 
    if (n > 2 and k == 1) : 
        return n 
   
    return -1
