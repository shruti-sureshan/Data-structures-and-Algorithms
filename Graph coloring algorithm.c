#include<stdio.h>
#include<conio.h>
void mcoloring(int k);
void nextvalue(int k);
int x[10],k,n,m,a[10][10],i,j;
void main()
{
clrscr();
for(i=1;i<=n;i++)
{
x[i]=0;
}
printf("enter the no of node\n");
scanf("%d",&n);
printf("enter the no of colors\n");
scanf("%d",&m);
printf("enter the graph\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&a[i][j]);
}
}
mcoloring(1);
getch();
}

void mcoloring(int k)
{
do
{
nextvalue(k);
if(x[k]==0)
return;
if(k==n)
{
for(i=1;i<=n;i++)
{
printf("%d\t",x[i]);
}
printf("\n");   }
else
{
mcoloring(k+1);
}}while(1);
}

void nextvalue(int k)
{
do
{
x[k]=(x[k]+1)%(m+1);
if(x[k]==0)
return;
for(j=1;j<=n;j++)
{
if((a[k][j]!=0) && (x[k]==x[j]))
break;
}
if(j==n)
return;
}while(1);
}
