#include<stdio.h>
#include<conio.h>
int visited[10],adj[10][10],n,e,s;
int q[100],front=-1,rear=-1;
int directed =0;
void bfs()
{
int r=0,i;
rear=front=0;
q[rear]=s;
visited[s]=1;
do
{
r=q[front++];
printf("%d ",r);
for(i=0;i<n;i++)
 {
  if(adj[r][i]==1 && visited[i]==0)
   {
    q[++rear]=i;

    visited[i]=1;
   }
 }
}while(front==rear || front <rear);
}
void dfs()
{
for(int j=0;j<n;j++)
   visited [j]=0;
int r,i;
int st[10],top=-1;
//scanf("%d",&sc);
st[++top]=s;
visited[s]=1;
do
{
r=st[top--];
printf("%d ",r);
for(i=0;i<n;i++)
 {
  if(adj[r][i]==1 && visited[i]==0)
  {
   st[++top]=i;
   visited[i]=1;
 }
}
}
while(top>=0);
}

void main()
{
clrscr();
int ch,v1,v2,i,j;
printf("Enter the number of vertices");
scanf("%d",&n);
printf("Enter the number of edges");
scanf("%d",&e);
printf("Enter 1 for directed,0 for undirected");
scanf("%d",&directed) ;
for(i=0;i<n;i++)
  for(j=0;j<n;j++)
     adj[i][j]=0;
for(i=0;i<e;i++)
{
  printf("Enter v1 and v2 ");
  scanf("%d %d",&v1,&v2);
  adj[v1][v2]=1;
    if(directed==0)
       adj[v2][v1]=1;
}
for(i=0;i<n;i++)
   visited [i]=0;
printf("Enter the source vertex");
scanf("%d",&s);
do
{
printf("\n***MAIN MENU***");
printf("\nEnter 1.Breadth First Seacrch");
printf("\nEnter 2.Depth First Search");
printf("\nEnter 3.EXIT");
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:
  bfs();
  break;
case 2:
  dfs();
  break;
}
}
while(ch!=3);
getch();
}
/*
Enter the number of vertices4
Enter the number of edges8
Enter 1 for directed,0 for undirected1
Enter v1 and v2 0 1
Enter v1 and v2 0 2
Enter v1 and v2 1 0
Enter v1 and v2 1 3
Enter v1 and v2 2 0
Enter v1 and v2 2 3
Enter v1 and v2 3 1
Enter v1 and v2 3 2
Enter the source vertex1

***MAIN MENU***
Enter 1.Breadth First Search
Enter 2.Depth First Search
Enter 3.EXIT
Enter your choice:1
1 0 3 2
***MAIN MENU***
Enter 1.Breadth First Search
Enter 2.Depth First Search
Enter 3.EXIT
Enter your choice:2
1 3 2 0
***MAIN MENU***
Enter 1.Breadth First Search
Enter 2.Depth First Search
Enter 3.EXIT
Enter your choice:3 */

