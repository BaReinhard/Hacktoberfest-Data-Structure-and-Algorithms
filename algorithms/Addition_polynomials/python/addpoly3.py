def adpoly(l,d,c):
    lis=[]
    k=0
    for i in range(0,len(l)):
        coeff=l[i][0]
        for j in range(0,len(d)):
          for k in range(0,len(c)):
				
               if((l[i][1]==d[j][1])):
                  coeff=coeff+(l[j][0])
               if((l[i][1]==c[k][1])):
                  coeff=coeff+(l[j][0])
               if((c[i][1]==d[j][1])):
                  coeff=coeff+(l[j][0])
        lis.append([coeff,l[i][1]])
        
    print(lis)

l=[[-2,1]]
m=[[2,1]]
c=[[8,7]]

adpoly(l,m,c)
