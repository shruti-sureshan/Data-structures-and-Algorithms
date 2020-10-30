#include<conio.h>
#include<stdio.h>
#define max 3
int top=-1;
void main()
{
 	clrscr();
 	int s[max],ch,choice,x,i;
 	void push(int s[max],int x);
 	void pop(int s[max]);
 	void peek(int s[max]);
 void display(int s[max]);
 do
 {
  	printf("1.push\n");
 	 	printf("2.pop\n");
 	 	printf("3.peek\n");
  		printf("4.display\n");
  		printf("Enter your choice\n");
 	 	scanf("%d",&ch);
  		switch(ch)
 	 	{
  			 case 1:printf("Enter data\n");
	 	 		scanf("%d",&x);
	  			push(s,x);
	  		               break;
   			case 2:pop(s);
	 		              break;
   			case 3:peek(s);
	  			break;
   			case 4:display(s);
	  			break;
  	}
 		 printf("Press 1 to continue\n");
  		scanf("%d",&choice);
  	}while(choice==1);
  	getch();
  }
  void push(int s[max],int x)
  {
   	if(top>=max-1)
   	{
   	 	printf("Stack overflow\n");
   	}
   	else
   	{
   		 top++;
    		s[top]=x;
 	  }
  }
  void pop(int s[max])
  {
   	if(top==-1)
   	{
   	 	printf("Stack overflow\n");
   	}
  	 else
   	{
  	 	 printf("Popped element is %d\n",s[top]);
  		 top--;
   	}
  }
  void peek(int s[max])
  {
   	if(top==-1)
   	{
    		printf("Stack overflow\n");
   	}
   	else
   	{
    		printf("Topmost element id %d\n",s[top]);
   	}
  }
  void display(int s[max])
  {
   	int i;
  	 if(top==-1)
   	{
    		printf("Stack underflow\n");
   	}
   	else
   	{
    		printf("Stack elements are:\n");
    		for(i=top;i>=0;i--)
    		{
     			printf("%d\n",s[i]);
   		 }
   	}
  }
