#include<stdio.h>
#include<conio.h>
#include<string.h>
char c[10][10],b[10][10],x[10],y[10];
int m,n,i,j;
void lcsp(int i,int j);
void lcs();
void main()
{
clrscr();
printf("Enter 1st string\n");
scanf("%s",x);
printf("enter 2nd string\n");
scanf("%s",y);
lcs();
printf("LCS is :");
lcsp(m,n);
getch();
}

void lcsp(int i,int j)
{
 if(i==0 || j==0)
 return;
 else if(b[i][j]=='D')
 {
  lcsp(i-1,j-1);
  printf("%c",x[i-1]);
 }
 else if(b[i][j]=='T')
 {
  lcsp(i-1,j);
 }
 else
  lcsp(i,j-1);
}
void lcs()
{
 m=strlen(x);
 n=strlen(y);
 for(i=0; i<m; i++)
 {
  c[i][0]=0;
 }
 for(j=0; j<n; j++)
 {
  c[0][j]=0;
 }
 for(i=1;i<=m;i++)
 {
   for(j=1;j<=n;j++)
   {
    if(x[i-1]==y[j-1])
    {
     c[i][j]=c[i-1][j-1]+1;
     b[i][j]='D';
    }
    else if(c[i-1][j]>=c[i][j-1])
    {
     c[i][j]=c[i-1][j];
     b[i][j]='T';
    }
    else
    {
     c[i][j]=c[i][j-1];
     b[i][j]='L';
    }
  }
 }
 }
