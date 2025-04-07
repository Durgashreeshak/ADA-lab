#include<stdio.h>
int max(int,int);
int dynamicknap(int n,int m,int p[],int w[])
{
	if(n==0||m==0)
		return 0;
	if(w[n-1]>m)
		return dynamicknap(n-1,m,p,w);
	else
		return max(dynamicknap(n-1,m,p,w),dynamicknap(n-1,m-w[n-1],p,w)+p[n-1]);
}
int max(int a,int b)
{
	return (a>b)?a:b;
}
void main()
{
	int n,i,m,p[10],w[10];
	printf("Enter the number of items and maximum capacity:");
	scanf("%d%d",&n,&m);
	printf("Enter the items profit:");
	for(i=0;i<n;i++)
	scanf("%d",&p[i]);
	printf("Enter the items weight:");
	for(i=0;i<n;i++)
	scanf("%d",&w[i]);
	printf("Maximum profit is %d",dynamicknap(n,m,p,w));
}	
