#include<stdio.h>
int i,j,a,b,u,v,min,parent[10],n,mincost=0,edges=0,cost[10][10];
int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}
void unite(int i,int j)
{
	parent[j]=i;
}
void main()
{
	printf("Enter number of vertices:");
	scanf("%d",&n);
	printf("Enter cost adjacency matrix (0 = no edge): \n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		scanf("%d",&cost[i][j]);
		if(cost[i][j]==0)
			cost[i][j]=999;
	}
	printf("Edges in MST:\n");
	while(edges<n-1)
	{
		min=999;
		for(i=1;i<=n;i++)
	        for(j=1;j<=n;j++)
	        if(cost[i][j]<min)
	        {
	        	min=cost[i][j];
	        	a=i;
	        	b=j;
	        }
	        u=find(a);
	        v=find(b);
	        if(u!=v)
	        {
	        	unite(u,v);
	        	mincost+=min;
	        	printf("Edge (%d, %d)-> %d\n",a,b,min);
	        	edges++;
	        }
	        cost[a][b]=cost[b][a]=999;
	 }
	 printf("Total cost=%d\n",mincost);
}
























