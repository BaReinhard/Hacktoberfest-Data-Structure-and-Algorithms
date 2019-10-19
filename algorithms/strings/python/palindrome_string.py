s1=input("enter a string: ")
i=0
j=len(s1)-1
flag=0;
for i in range(len(s1)//2):
    flag=0;
    if s1[i]==s1[j]:
     flag=0
    else:
        flag=1
        break;
    j=j-1
      
    
if flag==0:
    print("String is paindrome")
else:
    print("String is Not palindrome")
