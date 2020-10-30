#include<stdio.h>
#include<conio.h>
#define max 3
int r=-1,f=-1,q[max];
void main()
{
 clrscr();
 void insert(int x);
 void del();
 void display();
 int ch,choice,x;
 do
 {
  printf("1.Insert\n2.Delete\n3.Display\n");
  printf("Enter your choice\n");
  scanf("%d",&ch);
  switch(ch)
  {
  case 1: printf("Enter data\n");
	  scanf("%d",&x);
	  insert(x);
	  break;
  case 2: del();
	  break;
  case 3: display();
	  break;
  }
  printf("Press 1 to continue\n");
  scanf("%d",&choice);
 }while(choice==1);
  getch();
}

void insert(int x)
{
 if(f==(r+1)%max)
 {
  printf("QUEUE IS FULL\n");
 }
 else
 {
  if(f==-1 && r==-1)
  {
   f=r=0;
  }
 else
 {
  r=(r+1)%max;
 }

 q[r]=x;
}
}
void del()
{
 if(f==-1 && r==-1)
 {
  printf("QUEUE IS EMPTY\n");
 }
 else
 {
 if(f==r)
 {
 printf("deleting %d",q[f]);
  f=r=-1;
 }
 else
 {
 printf("%d",q[f]);
 f=(f+1)%max;
 }
}
}
void display()
{
 int i;
 if(f==-1 && r==-1)
 {
  printf("QUEUE IS EMPTY\n");
 }
 else
 {
  i=f;
  while(i!=r)
  {
  printf("%d\t",q[i]);
  i=(i+1)%max;
  }
  printf("%d\n",q[i]);
 }
}
