#include<stdio.h>
int lsearch(int*,int,int);
int bsearch(int*,int,int);
void main()
{
int a[50],ele, n,i=0,comp1,comp2;
printf("enter the array size\n");
scanf("%d",&n);
printf("enter the sorted array:\n");


for(i=0;i<n;i++)
{
	scanf("%d",&a[i]);
}


printf("enter the element you want to search:\n");
scanf("%d",&ele);

		comp1=lsearch(a,n,ele);
		comp2=bsearch(a,n,ele);

printf("linear search comparison:%d\n",comp1);
printf("binary search comparison:%d\n",comp2);
if(comp1<comp2)
	printf("linear search is effective\n");
else
	printf("binary search is effective\n");
}


int lsearch(int* a,int n,int ele)
{
int i=0,comparison=0;


for(i=0;i<n;i++)
{
	if(ele==a[i])
	{
		printf("the element is found at %d position\n",i+1);
	}
	i++;
	comparison++;
}

return comparison;
}


int bsearch(int*a,int n,int ele)
{
int i,comparison=0,beg=0,last=n-1;
int mid=((beg+last)/2);
while(beg<=last)
{
if(ele>a[mid])
	beg=mid+1;
else if(ele<a[mid])
	last=mid-1;
else if(ele==a[mid])
{	
printf("element found at pos:%d",mid);
break;
}
mid=(beg+last)/2;
comparison++;
}
return comparison;
}
	


