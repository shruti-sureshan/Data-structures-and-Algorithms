#include<stdio.h>
#include<conio.h>
int n,q,p[10],m[10][10],s[10][10],i,j,k,l;
void print(int i,int j);
void main()
{
clrscr();
printf("enter the no of matrices\n");
scanf("%d",&n);
printf("enter the dimension\n");
for(i=1;i<=n+1;i++)
{
scanf("%d",&p[i]);
}

for(i=1;i<=n;i++)
	m[i][i]=0;
for(l=2;l<=n;l++)
{
for(i=1;i<=n-l+1;i++)
{
j=i+l-1;
m[i][j]=9999;
for(k=i;k<=j-1;k++)
{
q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
if(q<m[i][j])
{
m[i][j]=q;
s[i][j]=k;
}
}
 }     }
print(1,n);

getch();
}
void print(int i,int j)
{
if(i==j)
 {
 printf("A%d",i);
 }
else
{
 printf("(");
 print(i,s[i][j]);
 print(s[i][j]+1,j);
 printf(")");
}
}
