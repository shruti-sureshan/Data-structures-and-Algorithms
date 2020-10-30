#include<conio.h>
#include<stdio.h>
#include<malloc.h>
void inorder(struct node *t);
void preorder(struct node *t);
void postorder(struct node *t);
int height(struct node *t);
int internal(struct node *t);
int external(struct node *t);
int nodes(struct node *t);
void largest();
void smallest();
struct node *mirror(struct node *t);
struct node *recbins(struct node *t);
struct node *itbins(struct node *t);
void delete0(struct node *root,int m);
struct node* delete2(struct node* parnode,struct node*d);
struct node* delete1(struct node* parnode,struct node*d);
struct node *create();

struct node
{
 	int data;
 	struct node *l,*r;
}*root=NULL;
int a;
void main()
{
 clrscr();
 	struct node *t,*r,*s;
 	int ch,h,m,g,j,i,choice;
 	do
 	{
  printf("1.CREATE\n2.INORDER\n3.PREORDER\n4.POSTORDER\n5.HEIGHT\n6.smallest\n7.largest\n8.recursive search\n9.iterative search\n10.mirror\n11.delete\n12.internal\n13.external\n14.nodes\nEnter your choice\n");
  		scanf("%d",&ch);

  		switch(ch)
  		{
   		case 1:root=create();
	  		break;
   		case 2:inorder(root);
	  		break;
   		case 3:preorder(root);
	  		break;
   		case 4:postorder(root);
	  		break;
   		case 5:h=height(root);
	  		printf("height is %d\n",h);
	  		break;
   		case 6:smallest();
			break;
   		case 7:largest();
			break;
   		case 8:printf("enter value to be searched\n");
	    		scanf("%d",&a);
	    		r=recbins(root);
			if(r==NULL)
				printf("element not found\n");
			else
				printf("element found\n");
			break;
   		case 9:s=itbins(root);
			if(s==NULL)
				printf("element not found\n");
			else
				printf("element found\n");

			break;
   		case 10:mirror(root);
	   		break;
   		case 11:printf("enter the element to be deleted\n");
	   		scanf("%d",&m);
	   		delete0(root,m);
	   		break;
   		case 12:g=internal(root);
	    		printf("internal nodes %d\n",g);
	  		break;
   		case 13:j=external(root);
	   		printf("external nodes %d\n",j);
	   		break;
   		case 14:i=nodes(root);
	   		printf("nodes %d\n",i);
	   		break;

  	}
  	printf("Press 1 to continue\n");
  	scanf("%d",&choice);
 	}while(choice==1);
 	getch();
}

struct node *create()
{
 	int x,found;
 	struct node *n,*t,*parent;
 	printf("Enter data\n");
 	scanf("%d",&x);
 	n=(struct node *)malloc(sizeof(struct node));
 	n->data=x;
 	n->l=n->r=NULL;
 	if(root==NULL)
 	{
  		root=n;
 	}
 	else
 	{
  		found=0;
  		t=parent=root;
  		while(t && found==0)
  		{
   		parent=t;
   		If(t->data==x)
   		{
    			found=1;
   		}
  	 	else if(x<t->data)
   		{
    			t=t->l;
   		}
   		else
   		{
    			t=t->r;
   		}
  }
  if(found==1)
  {
   	printf("Duplicate not allowed\n");
  }
  else
  {
   	if(x<parent->data)
   	{
    		parent->l=n;
   	}
   	else
   	{
    		parent->r=n;
   	}
  }
 }
 return(root);
}

void inorder(struct node *t)
{
 	if(t)
 	{
 		inorder(t->l);
 		printf("%d\t",t->data);
 		inorder(t->r);
 }
}

void preorder(struct node *t)
{
 	if(t)
 	{
  		printf("%d\t",t->data);
  		preorder(t->l);
  		preorder(t->r);
 	}
}

void postorder(struct node *t)
{
 	if(t)
 	{
  		postorder(t->l);
  		postorder(t->r);
  		printf("%d\t",t->data);
 	}
}

int height(struct node *t)
{
int lh,rh;
if(t==NULL)
{
 		return 0;
}
else
{
 		lh=height(t->l);
 		rh=height(t->r);
 		if(lh>rh)
 		{
  			return (lh+1);
 	}
 		else
 		{
  			return (rh+1);
 	}
}
}

void smallest()
{
struct node *t;
t=root;
 while(t->l!=NULL)
 	{
  		t=t->l;
 	}
 	printf("smallest is %d",t->data);
}

void largest()
{
 	struct node *t;
 t=root;
 	while(t->r!=NULL)
 	{
  		t=t->r;
 	}
 	printf("largest is %d",t->data);
}


struct node *recbins(struct node *t)
{
if(t==NULL)
 	return t;
if(t->data==a)
 		return t;
if(a<t->data)
 		return (recbins(t->l));
else
 		return (recbins(t->r));
}

struct node *itbins(struct node *t)
{
int b;
 	printf("enter element to be searched\n");
scanf("%d",&b);
 	while(t && t->data!=b)
 	{
  		if(b<t->data)
   			t=t->l;
  		else
   			t=t->r;
 	}
 	return t;
}

struct node *mirror(struct node *t)
{
 	struct node *ptr;
 	if(t!=NULL)
 	{
 		 mirror(t->l);
  		mirror(t->r);
  		ptr=t->l;
  		t->l=t->r;
  		t->r=ptr;
 }
}
int nodes(struct node* t)
{
	{
	int LH,RH;
	if(t==NULL)
		return 0;
	else
	{
	 	LH=nodes(t->l);
	 	RH=nodes(t->r);
	 	return(LH+1+RH);
	}
}
}
int external(struct node *t)
{
	if(t==NULL)
		return 0;
	else if(t->l==NULL&&t->r==NULL)
		return 1;
	else
	{
		return(external(t->l)+external(t->r));
	}

}
int internal(struct node *t)
{
struct node *l;
 	if(t==NULL || (t->l==NULL && t->r==NULL))
 		return 0;
 else
 	{
 		return(internal(t->l)+internal(t->r)+1);
 }
}
void delete0(struct node *root,int m)
{
  	struct node *parnode=NULL,*t,*d,*d1;
  	t=root;
  	while(t!=NULL&&t->data!=m)
  	{
     		parnode=t;
     		if(t->data>m)
     			t=t->l;
    		else
     			t=t->r;
  	}
  	if(t==NULL)
  		printf("\nElement not found.");
  	else d= t;
  		if(t->l!=NULL&&t->r!=NULL)
  		d1=delete2(parnode,d);
  	else
  		d1=delete1(parnode,d);
  		free(d1);
}
struct node* delete1(struct node* parnode,struct node*d)
{
	struct node *child=NULL;
	if(d->l!=NULL)
		child=d->l;
	else if(d->r!=NULL)
		child=d->r;
	else
		child=NULL;
	if(parnode==NULL)
		root=child;
	else if(d==parnode->l)
		parnode->l=child;
	else if(d==parnode->r)
		parnode->r=child;
		return(d);
}
struct node* delete2(struct node *parnode,struct node *d)
{
	struct node *p,*q,*succ,*presucc;
	p=d->r;
	q=d;
	while(p->l)
	{
	  	 q=p;
	   	p=p->l;
	}
	succ=p;
	presucc=q;
	p=delete1(presucc,succ);
	if(parnode!=NULL)
	{
	if(parnode->l==d)
	    	parnode->l=succ;
	    else
	    	parnode->r=succ;
	}
	else
		root=succ;
		succ->l=d->l;
		succ->r=d->r;
		return(d);
}
