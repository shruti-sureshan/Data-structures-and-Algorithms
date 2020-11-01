#include<stdio.h>
#include <conio.h>
float q[20],y[20];
void knapsack(int n, float w[], float p[], float m, int k[20])
{
   float x[20], temp, tp = 0;
   int i, j, u;
   u = m;
   for (i = 0; i < n; i++)
      {
      x[i] = 0.0;
      }
   for (i = 0; i < n; i++)
   {
      if (w[i] > u)
	 break;
      else
      {
	 x[i] = 1.0;
	 tp = tp + p[i];
	 u = u - w[i];
      }
   }
   if (i < n)
      x[i] = u / w[i];
   tp = tp + (x[i] * p[i]);
   for (i = 0; i < n; i++)
   {
      for (j = i + 1; j < n; j++)
      {
	 if (k[i] > k[j])
	 {
	    temp = k[j];
	    k[j] = k[i];
	    k[i] = temp;
	    
   temp = x[j];
	    x[j] = x[i];
	    x[i] = temp;
	 }
      }
   }
   printf("\nThe result table is - \n");
   printf("Item  Weight  Profit  Xi\n");
   for (i = 0; i < n; i++)
      printf("%d    %.2f     %.2f    %.2f\n",k[i], y[i], q[i], x[i]);
   printf("\nTotal profit is: %.2f\n", tp);
   printf("{");
   for(i=0;i<n;i++)
       printf(" %.2f,",x[i]);
   printf("}");
}
void main()
{
   float w[20], p[20], m;
   int n, i, j,k[20];
   float sort[20], temp;
   clrscr();
   printf("Enter the number of items : ");
   scanf("%d", &n);
   printf("Enter the item number, weight and profit of each %d objects : \n",n);
   for (i = 0; i < n; i++)
   {
      scanf("%d	 %f %f",&k[i], &w[i], &p[i]);
   }
   printf("Enter the capacity of knapsack : ");
   scanf("%f", &m);
   for (i = 0; i < n; i++)
   {
      sort[i] = p[i] / w[i];
      y[i]=w[i];
      q[i]=p[i];
   }
   for (i = 0; i < n; i++)
   {
      for (j = i + 1; j < n; j++)
      {
	 if (sort[i] < sort[j])
	 {
	    temp = sort[j];
	    sort[j] = sort[i];
	    sort[i] = temp;

	    temp = w[j];
	    w[j] = w[i];
	    w[i] = temp;

	    temp = p[j];
	    p[j] = p[i];
	    p[i] = temp;

	    temp = k[j];
	    k[j] = k[i];
	    k[i] = temp;
	 }
      }
   }
   knapsack(n, w, p, m,k);
   getch();
}
