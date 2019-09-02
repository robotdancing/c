#ifndef SORT_C
#define SORT_C
#include<stdio.h>
#include<stdlib.h>

void Swap(int *a,int *b)
{
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}

void PrintArr(int t[],int len)
{
	int i;
	for(i=0;i<len;i++)
		printf("%d, ",t[i]);
	printf("\n");
}

void BubbleSort(int a[],int len)
{
	int i,j;
	for(i=0;i<len;i++)
		for(j=1;j<len-i;j++)
		{
			if(a[j-1]>a[j])
				Swap(&a[j-1],&a[j]);
		}
}

void BubbleSort1(int a[],int len)
{
	int j,k,flag;
	k=len;
	flag=1;
	while(flag)
	{
		flag=0;
		for(j=1;j<k;j++)
		{
			if(a[j-1]>a[j])
			{
				Swap(&a[j-1],&a[j]);
				flag=1;
			}
		}
		k--;
	}
}

void BubbleSort2(int a[],int len)
{
	int j,k,flag;
	flag=len;
	while(flag)
	{
		k=flag;
		flag=0;
		for(j=1;j<k;j++)
			if(a[j-1]>a[j])
			{
				Swap(&a[j-1],&a[j]);
				flag=j;
			}
	}
}

void InsertSort(int a[],int len)
{
	int i,j,tmp;
	for(i=1;i<len;i++)
	{
		if(a[i-1]>a[i])
		{
			tmp=a[i];
			for(j=i-1;j>=0&&a[j]>tmp;j--)
			{
				a[j+1]=a[j];
			}
			a[j+1]=tmp;
			
		}
	}
}

void InsertSort1(int a[],int len)
{
	int i,j;
	for(i=1;i<len;i++)
		for(j=i-1;j>=0&&a[j]>a[j+1];j--)
			Swap(&a[j+1],&a[j]);
}

void ShellSort(int a[],int len)
{
	int i,j,gap;
	for(gap=len/2;gap>0;gap/=2)
		for(i=gap;i<len;i++)
			for(j=i-gap;j>=0&&a[j]>a[j+gap];j-=gap)
				Swap(&a[j],&a[j+gap]);
}

void SelectSort(int a[],int len)
{
	int i,j,min;
	for(i=0;i<len;i++)
	{
		min=i;
		for(j=i+1;j<len;j++)
			if(a[j]<a[min])
				min=j;
		Swap(&a[i],&a[min]);
	}
}

void QuickSort(int a[],int l,int r)
{
	int i,j,x;
	if(l<r)
	{
		i=l;
		j=r;
		x=a[l];
		while(i<j)
		{
			while(i<j&&a[j]>=x)
				j--;
			if(i<j)
				a[i++]=a[j];
			while(i<j&&a[i]<x)
				i++;
			if(i<j)
				a[j--]=a[i];
		}
		a[i]=x;
		QuickSort(a,l,i-1);
		QuickSort(a,i+1,r);
	}
}

//MergeSort begins.
void MergeArr(int a[],int first,int mid,int last,int tmp[])
{
	int k=0;
	int i=first,j=mid+1;
	int m=mid,n=last;
	while(i<=m&&j<=n)
	{
		if(a[i]<a[j])
			tmp[k++]=a[i++];
		else
			tmp[k++]=a[j++];
	}
	while(i<=m)
		tmp[k++]=a[i++];
	while(j<=n)
		tmp[k++]=a[j++];
	for(i=0;i<k;i++)
		a[first+i]=tmp[i];
}

void MergeD(int a[],int first,int last,int tmp[])
{
	if(first<last)
	{
		int mid;
		mid=(first+last)/2;
		MergeD(a,first,mid,tmp);
		MergeD(a,mid+1,last,tmp);
		MergeArr(a,first,mid,last,tmp);
	}
}

void MergeSort(int a[],int len)
{
	int *p;
	p=(int*)malloc(len*sizeof(int));
	if(!p)
		exit(0);
	MergeD(a,0,len-1,p);
	free(p);
}
//MergeSort ends.

//MinHeapSort begins.
void MinHeapFixDown(int a[],int i,int len)
{
	int j,tmp;
	j=2*i+1;
	tmp=a[i];
	while(j<len)
	{
		if(j+1<len&&a[j+1]<a[j])
			j++;
		if(a[j]>tmp)
			break;
		a[i]=a[j];
		i=j;
		j=2*i+1;
	}
	a[i]=tmp;
}

void MakeMinHeap(int a[],int len)
{
	int i;
	for(i=len/2-1;i>=0;i--)
		MinHeapFixDown(a,i,len);
}

void MinHeapSort(int a[],int len)
{
	int i;
	for(i=len-1;i>=1;i--)
	{
		Swap(&a[i],&a[0]);
		MinHeapFixDown(a,0,i);
	}
}
// MinHeapSort ends.

//MaxHeapSort begins.
void MaxHeapFixDown(int a[],int i,int len)
{
	int j,tmp;
	j=2*i+1;
	tmp=a[i];
	while(j<len)
	{
		if(j+1<len&&a[j+1]>a[j])
			j++;
		if(a[j]<tmp)
			break;
		a[i]=a[j];
		i=j;
		j=2*i+1;
	}
	a[i]=tmp;
}
void MakeMaxHeap(int a[],int len)
{
	int i;
	for(i=len/2-1;i>=0;i--)
		MaxHeapFixDown(a,i,len);
}
void MaxHeapSort(int a[],int len)
{
	int i;
	for(i=len-1;i>=1;i--)
	{
		Swap(&a[i],&a[0]);
		MaxHeapFixDown(a,0,i);
	}
}
 
int main()
{
	int s[]={5,5,6,8,3,2,4,8,9,7,1,2,98,6,5,6,66,7,8,9,100,7};
	int t[]={9,12,17,30,50,20,60,65,4,19};
//	BubbleSort(s,(sizeof(s)/sizeof(int)));
//	BubbleSort1(s,(sizeof(s)/sizeof(int)));
//	BubbleSort2(s,(sizeof(s)/sizeof(int)));
//	InsertSort(s,(sizeof(s)/sizeof(int)));
//	InsertSort1(s,(sizeof(s)/sizeof(int)));
//	ShellSort(s,(sizeof(s)/sizeof(int)));
//	SelectSort(s,(sizeof(s)/sizeof(int)));
//	QuickSort(s,0,(sizeof(s)/sizeof(int)-1));
//	MergeSort(s,(sizeof(s)/sizeof(int)));
//	PrintArr(s,sizeof(s)/sizeof(int));
//	MakeMinHeap(t,sizeof(t)/sizeof(int));
//	MinHeapSort(t,sizeof(t)/sizeof(int));
	MakeMaxHeap(t,sizeof(t)/sizeof(int));
	MaxHeapSort(t,sizeof(t)/sizeof(int));
	PrintArr(t,sizeof(t)/sizeof(int));
}
#endif
