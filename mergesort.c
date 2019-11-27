#include<stdio.h>
void merge(int a[],int l,int mid,int r)
{
	int c[25];
	int i=l,j=mid+1,k=l;
	while(i<=mid && j<=r)  
	{
		if(a[i]<=a[j])
				c[k++]=a[i++];	
		else
			c[k++]=a[j++];
	}
	while(i<=mid)
		c[k++]=a[i++];
	while(j<=r)
		c[k++]=a[j++];
	for(i=l;i<k;i++)
		a[i]=c[i];
}
void mergesort(int a[],int l,int r)
{
	int mid;
	if(l<r)
	{
		mid=(l+r)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,r);
		merge(a,l,mid,r);
	}
}
void main()
{
	int i,size,arr[25];
	printf("enter the size\n");
	scanf("%d",&size);
	printf("enter the array\n");
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
	printf("unsorted array\n");
	for(i=0;i<size;i++)
		printf("%d\t",arr[i]);
	mergesort(arr,0,size-1);
	printf("\nsorted array\n");
	for(i=0;i<size;i++)
		printf("%d\t",arr[i]);
}