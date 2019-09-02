#include <stdio.h>

int NoDuplicate(int a[],int n)
{
	int i,j;
	for(i=0,j=0;i<n-1;i++)
	{
		if(a[i]!=a[i+1])
			a[j++]=a[i];
	}
	a[j++]=a[n-1];
	return j;
}

int main()
{
	int test[]={1,1,2,3,4,5,6,7,8,9,9,10,11,12,15,15,16,16};
	int len=sizeof(test)/sizeof(int);
	int newlen=NoDuplicate(test,len);
	int i;
	for(i=0;i<newlen;i++)
		printf("%d ",test[i]);
	printf("\n");
	printf("ole len is:%d.\nnewlen is:%d\n",len,newlen);
}
