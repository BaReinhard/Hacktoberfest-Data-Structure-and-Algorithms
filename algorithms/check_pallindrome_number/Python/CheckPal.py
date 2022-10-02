#Python Program to check if the given number is palindrome or not


# Approach 1
def ispal(x):
    return str(x)==str(x)[::-1]

# Approach 2
def ispal1(n):
    t=int(n)
    p=0
    while t>0:
        d=t%10
        p=p*10+d
        t=t//10
    
    if n==p:
        return True
    
    else:
        return False

i=int(input("Enter the number you want to check:"))
r=ispal(i)
e=ispal1(i)

print(i, "is a palindrome:", r ," using the first approach.")
print(i,"is a palindrom:" , e ," using the second approach.")