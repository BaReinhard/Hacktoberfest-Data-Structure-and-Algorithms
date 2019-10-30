#beginning
n1 = 0
n2 = 1
count = 0
sizeInt = int(input("What size you want your sequence under 100?    "))
if sizeInt <= 0 or sizeInt>=100:
   print("Please enter a positive integer")
elif sizeInt == 1:
   print("Fibonacci sequence upto",sizeInt," terms:")
   print(n1)
else:
   print("Fibonacci sequence upto",sizeInt," terms:")
   while count < sizeInt:
       print(n1,end=' , ')
       nth = n1 + n2
       n1 = n2
       n2 = nth
       count += 1
