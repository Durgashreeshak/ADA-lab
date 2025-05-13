#include<stdio.h>
int main()
{
 int n,j,i,u,min,src,a[10][10],dist[10],visited[10];
 printf("Enter number of vertices:");
 scanf("%d",&n);
 printf("Enter the adjacency matrix:\n");
 for(i=1;i<=n;i++)
 for(j=1;j<=n;j++)
 scanf("%d",&a[i][j]);
 printf("Enter source vertex:");
 scanf("%d",&src);
 for(i=1;i<=n;i++)
 {
  dist[i]=999;
  visited[i]=0;
 }
 dist[src]=0;
 for(i=1;i<=n;i++)
 {
  min=999;
  for(j=1;j<=n;j++)
  {
   if(!visited[j]&&dist[j]<min)
   {
    min=dist[j];
    u=j;
   }
  }
  visited[u]=1;
  for(j=1;j<=n;j++)
  {
   if(!visited[j]&&a[u][j]&&dist[u]+a[u][j]<dist[j])
   {
    dist[j]=dist[u]+a[u][j];
   }
  }
 }
 printf("Shortest distances from vertex %d:\n",src);
 for(i=1;i<=n;i++)
 printf("To %d: %d\n",i,dist[i]);
 return 0;
}



























