#include<stdio.h>
#include<conio.h>
void quickr(int low,int a[],int high);
int partition(int low,int a[],int high);
void main()
{
int a[10],n,i,l,h;
printf("enter no of elements");
scanf("%d",&n);
printf("enter value");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
l=0;
h=n-1;
quickr(l,a,h);
printf("the sorted array is \n");
for(i=0;i<n;i++)
{
printf("%d\n",a[i]);
}
getch();
}


void quickr(int low,int a[],int high)
{
int j;
if(low<high)
{
	  j=partition(low,a,high);
	   quickr(low,a,j-1);
	   quickr(j+1,a,high);
}
}
int partition(int low,int a[],int high)
{
int pivot,ub,lb,temp;
pivot=a[low];
ub=high;
lb=low;
while(lb<ub)
{
while(a[lb]<=pivot && lb<high)
lb++;
while(a[ub]>pivot)
ub--;
if(lb<ub)
{
temp=a[ub];
a[ub]=a[lb];
a[lb]=temp;
}
}
a[low]=a[ub];
a[ub]=pivot;
return ub;
}

/*output:							    º

enter no of elements5
enter value56
34
78
12
30
the sorted array is
12
30
34                                                                              
56                                                                              
78      */                                                                        
                                                                                
