#include<stdio.h>
static int count=0;
int search(int*,int,int,int,int);
void main()
{
int a[10],beg,mid,ele,last,n,i,pos;
printf("enter the size");
scanf("%d",&n);
beg=0;
last=n-1;
mid=((beg+last)/2);
printf("enter the sorted array");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("enter the element to be searched");
scanf("%d",&ele);
pos=search(a,beg,last,n,ele);
printf("\n%d:position",pos+1);
printf("\nnumber of comparisons:%d",count);
}
int search(int a[],int beg,int last,int n,int ele)
{
int mid=((beg+last)/2);
count++;
if(ele<a[mid])
 return search(a,beg,mid-1,n,ele);
else if(ele>a[mid])
	return search(a,mid+1,last,n,ele);
else if(a[mid]==ele)
	return mid;
}
 
	




