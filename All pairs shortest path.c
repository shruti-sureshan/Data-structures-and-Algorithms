#include<stdio.h>
#include<conio.h>
int min(int a,int b);
int a[10][10];
void main()
{
clrscr();
int i,j,k,n;
printf("enter no of nodes\n");
scanf("%d",&n);	
printf("enter the values\n");
for(i=1;i<=n;i++)
{
 for(j=1;j<=n;j++)
		{
 scanf("%d",&a[i][j]);
 }
}
printf("the original matrix\n");
for(i=1;i<=n;i++)
{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
}

for(k=1;k<=n;k++)
{
printf("\nPASS:\n");
		for(i=1;i<=n;i++)
		{

			for(j=1;j<=n;j++)
			{
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
				printf("%d\t",a[i][j]);
			}
			printf("\n");
 }
}
printf("final matrix\n");
for(i=1;i<=n;i++)
{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
}
getch();
}
int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
