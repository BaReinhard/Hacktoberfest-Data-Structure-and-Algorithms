

Program:
#include<stdio.h>
#include<conio.h>
void main()
{
int st[100],ch,top=-1,size,n,i;
clrscr();
printf("Enter the size of stack:");
scanf("%d",&size);
do
{
printf("\nChoose an option:");
printf("\n1.Push");
printf("\n2.Pop");
printf("\n3.Peek");
printf("\n4.Display");
printf("\n5.Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
   {
   printf("\nTo Push:\n");
   if(top==size-1)
    printf("\nStack Full\n");
   else
    {
    printf("\nEnter the element:\n");
    scanf("%d",&n);
    top=top+1;
    st[top]=n;
    printf("\nOperation Successful..!!\n");
    }
    break;
   }
case 2:
  {
  printf("\nTo pop\n");
  if(top==-1)
   printf("\nStack Empty\n");
  else
   {
   printf("\nElement Deleted:%d\n",st[top]);
   top=top-1;
   printf("\nOperation Successful...!!\n");
   }
   break;
  }
case 3:
 {
 printf("\nTo Peek\n");
 if(top==-1)
  printf("\nStack Empty\n") ;
 else
 {
 printf("Element is:%d",st[top]);
 }
 break;
 }
case 4:
 {
 printf("\nTo Display\n");
 if(top==-1)
  printf("\nStack Empty\n");
 else
 {
 printf("\nElements of stack are:\n");
 for(i=0;i<=top;i++)
  printf("%d\n",st[i]);
 printf("\n");
 }
 break;
 }
case 5:
  {
  printf("\nExit\n");
  break;
  }
default:
 printf("\nOOPS!! Wrong value\n");
 }
}while(ch!=5);

getch();
}


Output
Choose an option:                                                               
1.Push                                                                          
2.Pop                                                                           
3.Peek                                                                          
4.Display                                                                       
5.Exit                                                                          
1

Enter the Element
23
Operation Successful...!!


Choose an option:                                                               
1.Push                                                                          
2.Pop                                                                           
3.Peek                                                                          
4.Display                                                                       
5.Exit
3

To Peek

Element is:23


Choose an option:                                                               
1.Push                                                                          
2.Pop                                                                           
3.Peek                                                                          
4.Display                                                                       
5.Exit
2

Element Deleted :23

Operation Successful...!!                                                       
                                                                                
Choose an option:                                                               
1.Push                                                                          
2.Pop                                                                           
3.Peek                                                                          
4.Display                                                                       
5.Exit                                                                          
4                                                                               
                                                                                
To Display                                                                      
                                                                                
Stack Empty                                                                     
                                                                                
Choose an option:                                                               
1.Push                                                                          
2.Pop                                                                           
3.Peek                                                                          
4.Display                                                                       
5.Exit                                                                          
5                                                                               
                                                                                
Exit                                                                            
                                                                                

