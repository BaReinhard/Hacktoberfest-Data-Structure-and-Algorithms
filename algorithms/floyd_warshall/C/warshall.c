#include<stdio.h>
#include<conio.h>
#include<math.h>
int max(int,int);
void warshal(int p[10][10],int n)
{
 int i,j,k;
 for(k=1;k<=n;k++)
  for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
    p[i][j]=max(p[i][j],p[i][k]&&p[k][j]);
}
int max(int a,int b)
{                                                       ;
if(a>b)
 return(a);
else
 return(b);
}
void main()
{
 int p[10][10]={0},n,e,u,v,i,j;
 clrscr();
 printf("n Enter the number of vertices:");
 scanf("%d",&n);
 printf("n Enter the number of edges:");
 scanf("%d",&e);
 for(i=1;i<=e;i++)
 {
  printf("n Enter the end vertices of edge %d:",i);
  scanf("%d%d",&u,&v);
  p[u][v]=1;
 }
 printf("n Matrix of input data: n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
   printf("%dt",p[i][j]);
  printf("n");
 }
 warshal(p,n);
 printf("n Transitive closure: n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
   printf("%dt",p[i][j]);
  printf("n");
 }
 getch();
}
