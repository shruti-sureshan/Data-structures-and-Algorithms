#include<stdio.h>
#include<conio.h>
void dij(int n, int v, int cost[10][10])
{
  int i,j,u,count,w,visited[10],dist[10],min,path[10];
  for(i=0;i<n;i++)
  {
    visited[i]=0;
    dist[i]=cost[v][i];
    path[i]=0;
  }
  dist[v]=0;
  count=2;
  while(count<=n)
  {
    min=99;
    for(w=0;w<n;w++)
    {
      if(dist[w]<min && !visited[w])
      {
	 min= dist[i];
	 u=w;
      }
    }   // end for
    visited[u]=1;
    count++;
    for(w=0;w<n;w++)
    {
      if(dist[u]+cost[u][w] < dist[w])
       {
	 dist[w] = dist[u] + cost[u][w];
	 path[w]=u;
       }
    }
    printf("Dist:\t");
    for(i=0;i<n;i++)
	printf("%d\t",dist[i]);
    printf("\n");
    printf("path:\t");
    for(i=0;i<n;i++)
	printf("%d\t",path[i]);
    printf("\n\n");
  }  // end while



 }   // end function
void main()
{
clrscr();
int n,v,e,adj[10][10],v1,v2,w,i,j;
printf("Enter the number of nodes");
scanf("%d",&n);
printf("Enter the number of edges:");
scanf("%d",&e);
for( i=0;i<n;i++)
{
     for(j=0;j<n;j++)
       {
		if(i==j)
		    adj[i][j]=0;
		else
		    adj[i][j]=99;
       }
}
/*
for(int k=1;k<=e;k++)
{
  printf("Enter v1 and v2 ");
  scanf("%d %d",&v1,&v2);
  printf("Enter the weight of the edge:");
  scanf("%d",&w);
  adj[v1][v2]=w;
}             */
for(i=0;i<n;i++)
{
 for(j=0;j<n;j++)
 {
  scanf("%d",&adj[i][j]);
 }
}
dij(n,0,adj);
getch();
}
