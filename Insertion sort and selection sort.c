#include<stdio.h>
#include<conio.h>
void insertion(int a[],int n);
void selection(int a[],int n);
void main()
{
clrscr();
int a[20],i,n,ch,choice;
printf("Enter no of elements\n");
scanf("%d",&n);
printf("Enter the elements\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
do
{
printf("1.Insertion sort\n2.Selection sort\nEnter your choice\n");
scanf("%d",&ch);
switch(ch)
{
 case 1:insertion(a,n);
 break;
 case 2:selection(a,n);
 break;
}
 printf("press 1 to continue\n");
 scanf("%d",&choice);
}while(choice==1);
getch();
}

void insertion(int a[],int n)
{
int j,k,key,i;

 for(j=1;j<n;j++)
 {
  key=a[j];
  k=j-1;
  while(k>=0 && a[k]>key)
  {
   a[k+1]=a[k];
   k=k-1;
  }
  a[k+1]=key;
  printf("\n pass %d\n",j);
  for(i=0;i<=n-1;i++)
  printf("%d\t",a[i]);
 }
}

void selection(int a[],int n)
{
int i,j,pos,large,k;
for(i=n-1;i>=0;i--)
{
  large=a[0];
  pos=0;
  for(j=1;j<=i;j++)
  {
   if(a[j]>large)
   {
    large=a[j];
    pos=j;
   }
  }
   a[pos]=a[i];
   a[i]=large;
  printf("\n pass %d\n",n-i);
  for(k=0;k<=n-1;k++)
  printf("%d\t",a[k]);
}
}
