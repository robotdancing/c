#include "ShellSort.h"

int main()
{
	int a[]={22,4,3,22,5,6,44,67,21,10,43,34,78,17,33,63};
	int len=sizeof(a)/sizeof(int);
	ShellSort(a,len);
	int i;
	for(i=0;i<len;i++)
		printf("%d ",a[i]);
	printf("\n");
	int b[]={22,4,3,22,5,6,44,67,21,10,43,34,78,17,33,63};
	BubbleSort(b,len);
	for(i=0;i<len;i++)
		printf("%d ",b[i]);
	printf("\n");
	int c[]={22,4,3,22,5,6,44,67,21,10,43,34,78,17,33,63};
	QuickSort(c,0,len-1);
	for(i=0;i<len;i++)
		printf("%d ",c[i]);
	printf("\n");
	int d[]={22,4,3,22,5,6,44,67,21,10,43,34,78,17,33,63};
	SelectSort(d,len);
	for(i=0;i<len;i++)
		printf("%d ",d[i]);
	printf("\n");
	int e[]={22,4,3,22,5,6,44,67,21,10,43,34,78,17,33,63};
	InsertSort(e,len);
	for(i=0;i<len;i++)
		printf("%d ",e[i]);
	printf("\n");
	int f[]={22,4,3,22,5,6,44,67,21,10,43,34,78,17,33,63};
	MergeSort(f,len);
	for(i=0;i<len;i++)
		printf("%d ",f[i]);
	printf("\n");
}	
