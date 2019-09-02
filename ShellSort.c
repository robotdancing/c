#ifndef SHELLSORT_C
#define SHELLSORT_C
#include "ShellSort.h"

void ShellSort(int a[],int length)
{
	int i,j,gap,tmp;
	for(gap=length/2;gap>0;gap/=2)
		for(i=gap;i<length;i++)
			for(j=i-gap;a[j]>a[j+gap]&&j>=0;j-=gap)
			{
				tmp=a[j+gap];
				a[j+gap]=a[j];
				a[j]=tmp;		
			}
}

void BubbleSort(int a[],int length)
{
	int i,j,tmp;
	for(i=length-1;i>=1;i--)
		for(j=0;j<=i-1;j++)
		{
			if(a[j+1]<a[j])
			{
				tmp=a[j+1];
				a[j+1]=a[j];
				a[j]=tmp;
			}
		}	
}

void QuickSort(int a[],int left,int right)
{
	if(left<right)
	{
		int i,j,x;
		i=left,j=right,x=a[left];
		while(i<j)
		{
		while(i<j&&a[j]>=x)
			j--;
		if(i<j)
		{
			a[i]=a[j];
			i++;
		}
		while(i<j&&a[i]<x)
			i++;
		if(i<j)
		{
			a[j]=a[i];
			j--;
		}
		}
		a[i]=x;
		QuickSort(a,left,i-1);
		QuickSort(a,i+1,right);
	}
}
void Swap(int *a,int *b)
{
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}	
void Swap1(int *a,int *b)
{
	if((*a)!=(*b))
	{
		(*a)^=(*b);
		(*b)^=(*a);
		(*a)^=(*b);
	}
}
void SelectSort(int a[],int n)
{
	int i,j,min,tmp;
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
				min=j;
		}
		Swap1(&a[i],&a[min]);
	}
}


void InsertSort(int a[],int n)
{
	int i,j;
	for(i=1;i<n;i++)
		for(j=i-1;a[j]>a[j+1];j--)
			Swap1(&a[j],&a[j+1]);
}
void Merge2Array(int a[],int first,int mid,int last,int tmp[])
{
	int i,j,n,m,k;
	i=first;
	j=mid+1;
	n=mid;
	m=last;
	k=0;
	while(i<=n&&j<=m)
		if(a[i]<a[j])
			tmp[k++]=a[i++];
		else
			tmp[k++]=a[j++];
	while(i<=n)
		tmp[k++]=a[i++];
	while(j<=m)
		tmp[k++]=a[j++];
	for(i=0;i<k;i++)
		a[first+i]=tmp[i];
}

void MergeSortD(int a[],int first,int last,int tmp[])
{
	if(first<last)
	{
		int mid;	
		mid=(first+last)/2;
		MergeSortD(a,first,mid,tmp);
		MergeSortD(a,mid+1,last,tmp);
		Merge2Array(a,first,mid,last,tmp);
	}
}

void MergeSort(int a[],int n)
{
	int *p;
	p=(int*)malloc(n*sizeof(int));
	if(!p)
		exit(0);
	MergeSortD(a,0,n-1,p);
	free(p);
}

#endif
