def palindrome(a):
    s=0
    y=a
    while(y>0):
        r=y%10
        s = s*10+r
        y=y//10
    if(a==s):
        print(a, "is palindrome")
    else:
        print(a, "not palindrome")
   
