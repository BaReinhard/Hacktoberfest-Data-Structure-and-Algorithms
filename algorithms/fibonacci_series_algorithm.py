a=0
b=1
n=input("enter the number of elements in series : ")
print (a)
print (b)
for i in range (n):
    show=a+b
    a=b
    b=show
    print (show)
    
