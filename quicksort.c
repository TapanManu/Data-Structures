#include<stdio.h>
int partition(int a[],int p,int r)
{
	int x,i,j,temp;
	x=a[r];
	i=p-1;
	for(j=p;j<r;j++)
	{
		if(a[j]<=x)
		{
			i++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[i+1];
	a[i+1]=a[r];
	a[r]=temp;
	return(i+1);
}
void quicksort(int a[],int p,int r)
{	int q;
	if(p<r)
	{
		q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}
void main()
{
	int arr[7]={90,80,70,50,60,10,30};
	int size=7,i;
	quicksort(arr,0,size-1);
	for(i=0;i<size;i++)
		printf("%d\t",arr[i]);
}