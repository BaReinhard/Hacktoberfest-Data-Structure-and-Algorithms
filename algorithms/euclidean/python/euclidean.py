def euclidean(a,b):#for natural numbers a,b
  
  #sanitize the inputs
  a=int(a)
  b=int(b)
  
  if(not(a and b)):#if either are 0
    return(0)
  
  if(b>a):#to have it so a>=b
    temp=a
    a=b
    b=temp
  
  while(1):
    remainder=a%b
    a=b
    b=remainder
    if(b==0):
      return(a)
