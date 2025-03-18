#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void mergesortD(int[],int,int);
void mergeC(int[],int,int,int);

void mergesortD(int a[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		mergesortD(a,low,mid);
		mergesortD(a,mid+1,high);
		mergeC(a,low,mid,high);
	}
}

void mergeC(int a[],int low,int mid,int high)
{
	int i=low;
	int j=mid+1;
	int k=low;
	int b[100000];
	while(i<=mid && j<=high)
	{
		if(a[i]<=a[j])
		{
			b[k]=a[i];
			i++;
			k++;
		}
		else
		{
			b[k]=a[i];
			j++;
			k++;
		}
	}
	while(j<=high)
	{
		b[k]=a[j];
		j++;
		k++;
	}
	while(i<=mid)
	{
		b[k]=a[i];
		i++;
		k++;
	}
	for(k=low;k<=high;k++)
	{
		a[k]=b[k];
	}
}

void generaterandomarray(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		a[i]=rand();
	}
}

int main()
{
	int set[]={5000,10000,15000,20000};
	int num=sizeof(set)/sizeof(set[0]);
	double time_taken[num];
	clock_t start,end;
	for(int i=0;i<num;i++)
	{
		int n=set[i];
		int*a=(int*)malloc(n*sizeof(int));
		generaterandomarray(a,n);
		start=clock();
		mergesortD(a,0,n-1);
		end=clock();
		time_taken[i]=((double)(end-start))/CLOCKS_PER_SEC;
		free(a);
	}
	printf("Set of numbers\t Time taken in seconds\n");
	for(int i=0;i<num;i++)
	{
	printf("%d\t\t\t%f\n",set[i],time_taken[i]);
	}
	return 0;
}




