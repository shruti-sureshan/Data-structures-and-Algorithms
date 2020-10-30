#include<stdio.h>
#include<conio.h>
void main()
{
int a[10];
intx,n,i;
int l,h;
int m,ch,res;
voidItBsearch(int a[],intx,intl,inth,int m);
intRecBsearch(int a[],intx,intl,inth,int m);
clrscr();
printf("enter no of elements\n");
scanf("%d",&n);
printf("enter values\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("enter value to be searched\n");
scanf("%d",&x);
l=0;
h=n-1;
m=(l+h)/2;
printf("1.Iterative search\n 2.recursive search\n");
printf("enter choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:ItBsearch(a,x,l,h,m);
break;
case 2:res=RecBsearch(a,x,l,h,m);
printf("element found at %d",res);
break;
}
getch();
}
voidItBsearch(int a[],intx,intl,inth,int m)
{
while(a[m]!=x && l<=h)
{
if(x<a[m])
{
h=m-1;
}
else
{
l=m+1;
}
m=(l+h)/2;
}
if(x==a[m])
{
printf("element found at %d",m);
}
else
{
printf("element not found\n");
}
}
intRecBsearch(int a[],intx,intl,inth,int m)
{
m=(l+h)/2;
if(a[m]==x)
{
return m;
}
if(l>h)
{
return -1;
}
if(x<a[m])
{
return(RecBsearch(a,x,l,m-1,m));
}
if(x>a[m])
return(RecBsearch(a,x,m,h+1,m));
}
