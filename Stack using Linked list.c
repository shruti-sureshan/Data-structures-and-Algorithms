#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
int data;
struct node *next;
}*start=NULL,*top=NULL;
void main()
{
clrscr();
void push(int x);
void pop();
void peek();
void display();
int choice,ch,x;
do
{
printf("1.push\n2.pop\n3.peek\n4.display\n");
printf("enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("enter element:\n");
	scanf("%d",&x);
	push(x);
	break;
case 2:pop();
	break;
case 3:peek();
	break;
case 4:display();
	break;
}
printf("press 1 to continue\n");
scanf("%d",&choice);
}while(choice==1);
getch();
}
void push(int x)
{
struct node *n=NULL;
n=(struct node *)malloc(sizeof(struct node));
n->data=x;
n->next=NULL;
if(top==NULL)
{
top=n;
}
else
{
n->next=top;
top=n;
}
}
void pop()
{
struct node *t;
if(top==NULL)
{
printf("stack is not created\n");
}
else
{
t=top;
printf("popping %d\n",t->data);
top=top->next;
free(t);
}
}
void peek()
{
if(top==NULL)
{
printf("stack is not created\n");
}
else
{
printf("The topmost element is %d\n",top->data);
}
}
void display()
{
struct node *t;
if(top==NULL)
{
printf("stack is not created\n");
}
else
{
t=top;
while(t)
{
printf("%d\t",t->data);
t=t->next;
}
}
}
