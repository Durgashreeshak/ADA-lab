#include<stdio.h>
void topological(int a[10][10],int n)
{
	int in[10],out[10],stack[10],top=-1,i,j,k=0;
	for(i=0;i<n;i++)
	{
		in[i]=0;
		for(j=0;j<n;j++)
		if(a[j][i]==1)
		in[i]++;
	}
        while(1)
	{
	for(i=0;i<n;i++)
	{
	if(in[i]==0)
	{
	stack[++top]=i;
	in[i]=-1;
	}
	}
	if(top==-1)
	break;
	out[k]=stack[top--];
	for(i=0;i<n;i++)
	{
	if(a[out[k]][i]==1)
		in[i]--;
	}
	k++;
}
printf("Topological sorting is:");
for(i=0;i<k;i++)
printf("%d\t",out[i]+1);
}
int main()
{
int a[10][10],n,i,j;
printf("Enter the number of vertices:");
scanf("%d",&n);
printf("Enter the adjacency matrix:");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&a[i][j]);
topological(a,n);
return 0;
}


