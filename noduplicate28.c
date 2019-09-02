#ifndef NODUPLICATE_C
#define NODUPLICATE_C
#include<stdio.h>

int NoDuplicate(int a[],int len)
{
	int i,j;
	for(i=0,j=0;i<len-1;i++)
	{
		if(a[i]!=a[i+1])
			a[j++]=a[i];
	}
	a[j++]=a[len-1];
	return j;
}

int main()
{
	int t[]={1,1,1,3,4,5,6,6,7,7,9,9,11,11,88,88,99,99,99};
	int n=sizeof(t)/sizeof(int);
	int k=NoDuplicate(t,n);
	int x=0;
	while(x<k)
	{
		printf("%d , ",t[x]);
		x++;
	}
	printf("\n");
	return 0;
}

#endif

