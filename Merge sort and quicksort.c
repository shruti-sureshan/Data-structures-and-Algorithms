#include<stdio.h>
#include<conio.h>
void mergesort(int low,int high,int a[]);
void merge(int low,int mid,int high,int a[]);
void quick(int a[],int lb,int ub);
int partition(int a[],int lb,int ub);
int n,i;
void main()
{
clrscr();
int i,a[10],ch,choice;
printf("Enter the no of element\n");
scanf("%d",&n);
printf("Enter the elements\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
do
{
printf("1.merge sort\n2.quick sort\nenter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:mergesort(0,n-1,a);
break;
case 2:quick(a,0,n-1);
break;
}
printf("press 1 to continue\n");
scanf("%d",&choice);
}while(choice==1);
getch();
}

void mergesort(int low,int high,int a[])
{
int mid,i;
if(low<high)
{
mid=(low+high)/2;
mergesort(low,mid,a);
mergesort(mid+1,high,a);
merge(low,mid,high,a);
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
printf("\n");
}
}

void merge(int low,int mid,int high,int a[])
{
int b[10];
int i,j,h,k;
h=low,j=mid+1,i=low;
while(h<=mid && j<=high)
{
if(a[h]<a[j])
{
b[i]=a[h];
h=h+1;
}
else
{
b[i]=a[j];
j=j+1;
}
i=i+1;
}
while(h<=mid)
{
b[i]=a[h];
h=h+1;
i=i+1;
}
while(j<=high)
{
b[i]=a[j];
j=j+1;
i=i+1;
}
for(k=low;k<=high;k++)
{
a[k]=b[k];
}
}

void quick(int a[],int lb,int ub)
{
 int pivot;
 if(lb<ub)
 {
 pivot=partition(a,lb,ub);

 quick(a,lb,pivot-1);
 quick(a,pivot+1,ub);
 }
}

int partition(int a[],int lb,int ub)
{
int t,x,up,down;
 x=a[lb];
 up=ub;
 down=lb;
 while(down<up)
 {
 while(a[down]<=x && down<ub)
 {
 down=down+1;
 }
 while(a[up]>x)
      {
	up=up-1;
      }
 if(down<up)
 {
  t=a[down];
  a[down]=a[up];
  a[up]=t;
  }
 }
 a[lb]=a[up];
 a[up]=x;
  for(i=0;i<n;i++)
 {
 printf("%d\t",a[i]);
 }
 printf("\n");
 return up;
}
