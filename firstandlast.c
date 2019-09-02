#include<stdio.h>
#include<stdlib.h>

int * FirstAndLast(int a[],int n,int i)
{
	int first,last,mid;
	int *result;
	result=(int*)malloc(2*sizeof(int));
	result[0]=-1;
	result[1]=-1;
	first=0;
	last=n-1;
	while(first<=last)
	{
		mid=first+(last-first)/2;
		if((mid==0||i>a[mid-1])&&a[mid]==i)
		{
			result[0]=mid;
			break;
		}
		else if(i<=a[mid])
			last=mid-1;
		else 
			first=mid+1;
	}
	first=0;
	last=n-1;
	while(first<=last)
	{
		mid=first+(last-first)/2;
		if((mid==n-1||i<a[mid+1])&&a[mid]==i)
		{
			result[1]=mid;
			break;
		}
		else if(i<a[mid])
			last=mid-1;
		else
			first=mid+1;	
	}
	return result;
}

int main()
{
	int ar[]={1,1,1,5,7,8,9,9,56,56,56};
	int *p;
	p=FirstAndLast(ar,11,1);
	printf("[%d,",p[0]);
	printf("%d]",p[1]);
	printf("\n");
	return 1;
}

