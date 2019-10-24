#include<stdio.h>
void printarray(int*a,int n)
{
int i;
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
}

void selection_sort(int* a,int n)
{
int i,j,small,temp,count=0;
for(i=0;i<n-1;i++)
{
	small=a[i];
	for(j=i+1;j<n;j++)
	{
			count++;
	 	if(a[j]<small)
				{
					temp=a[j];
					a[j]=small;
					small=temp;
				}
	}
	a[i]=small;
}
printf("\tarray after selction sort\n");
printarray(a,n);
printf("\n\tnumber of comparisons of selection sort:%d",count);
}

void bubble_sort(int*a,int n)
{
int i,j,temp,count=0;
for(i=0;i<n;i++)
{count++;
	for(j=0;j<n-i-1;j++)
	{
		count++;
		if(a[j]>a[j+1])
		{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
	}
}
printf("\tarray after bubble sort\n");
printarray(a,n);
printf("\n\tnumber of comparisons of bubble sort:%d",count);
}

void insertion_sort(int *a,int n)
{
	int i,j,key,count=0;
	for(i=1;i<n;i++)
	{
	count++;
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key)
		{	count++;
				a[j+1]=a[j];
				j=j-1;
		}
		a[j+1]=key;
	}
printf("\tarray after insertion sort\n");
printarray(a,n);
printf("\n\tnumber of comparisons of insertion sort:%d",count);
}

void main()
{
int a[10],i,n,ch;
int c=1;
printf("\tenter the size of the array:");
scanf("%d",&n);
printf("\tenter the array\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("\tunsorted array\n");
printarray(a,n);
do{
printf("\n\tenter your choice(1-3)\n");
printf("\t1.selection sort\n");
printf("\t2.bubble sort\n");
printf("\t3.insertion sort\n");
scanf("%d",&ch);
switch(ch)
{
	case 1:
			selection_sort(a,n);	
			break;
	case 2:
			bubble_sort(a,n);
			break;
	case 3:
			insertion_sort(a,n);
			break;
	default:
			printf("wrong case");
}
printf("\ndo you want to continue?(press 1 for continue)\n");
scanf("%d",&c);
}while(c==1);

}

 	

