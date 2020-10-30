#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void insert();
void del();
void display();
struct node
{
int data;
struct node *next;
}*f=NULL,*r=NULL;
void main()
{
clrscr();
int ch,choice;
do
{
printf("1.insert\n2.delete\n3.display\n");
printf("enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:insert();
       break;
case 2:del();
       break;
case 3:display();
       break;
}
printf("press 1 to continue\n");
scanf("%d",&choice);
}while(choice==1);
getch();
}

void insert()
{
struct node *n;
n=(struct node*)malloc(sizeof(struct node));
printf("enter data");
scanf("%d",&n->data);
n->next=NULL;
if(f==NULL && r==NULL)
{
 f=r=n;
}
else
{
 r->next=n;
 r=n;
}
}

void del()
{
struct node *t;
if(f==NULL)
{
 printf("queue is emplty");
}
else
{
 if(f==r)
 {
 t=f;
 printf("deleting %d",f->data);
 f=r=NULL;
 free(t);
 }
 else
 {
  printf("deleting %d",f->data);
  t=f;
  f=f->next;
  free(t);
 }
}
}

void display()
{
struct node *t;
 if(f==NULL)
 {
  printf("queue is empty");
 }
 else
 {
  for(t=f;t;t=t->next)
  printf("%d",t->data);
 }
}
