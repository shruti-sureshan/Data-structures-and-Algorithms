#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<ctype.h>
int pre(char ch);
 char in[20],post[20],s[20];
 int top=-1,i=0,j=0;
 float st[20],op1,op2;
void main()
{
 clrscr();
 	printf("enter  an expression\n");
 	scanf("%s",in);
 	for(i=0;in[i]!='\0';i++)
 {
  		switch(in[i])
  		{
   			case '(':   s[++top]=in[i];
	   			   break;
   			case ')':   while(s[top]!='(' && top>=0)
	   		 {
	    			 post[j++]=s[top--];
	 		   }
	  	  		top--;
	    			break;
   			case '+':
  			 case '-':
 			 case '*':
   			 case '/':
   			case '^':   while(pre(in[i])<=pre(s[top]) && top>=0)
	    		{
	     			post[j++]=s[top--];
	   		 }
	    		s[++top]=in[i];
	    		break;
   			default:post[j++]=in[i];
  		}
 }
 	while(top>=0)
 {
  		post[j++]=s[top--];
 	}
  	post[j]='\0';
  	printf("%s\n",post);
  	for(j=0;post[j]!='\0';j++)
  	{
   		if(isalnum(post[j]))
   		{
   			 if(isdigit(post[j]))
    			{
     				st[++top]=post[j]-'0';
    			}
   		else
   		{
    			printf("enter value for %c\n",post[j]);
    			scanf("%f",&st[++top]);
   		}
  	}
  	else
  	{
   		op2=st[top--];
   		op1=st[top--];
   		switch(post[j])
   		{
    		case '+':  st[++top]=op1+op2;
	     		break;
    		case '-':  st[++top]=op1-op2;
	     		break;
    		case '*':  st[++top]=op1*op2;
	     		break;
    		case '/':  st[++top]=op1/op2;
	     		break;
    		case '^':  st[++top]=pow(op1,op2);
	     		break;
 		}
 	}
 }
 	printf("%f",st[top]);
 	getch();
}
 int pre(char ch)
 {
  	if(ch=='^')
  	{
  		return 3;
  	}
  	if(ch=='*' || ch=='/')
  	{
   		return 2;
  	}
  	if(ch=='+' || ch=='-')
  	{
   		return 1;
  	}
  return 0;
 }
