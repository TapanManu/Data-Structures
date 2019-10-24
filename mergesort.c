#include<stdio.h>
void main()
{
int a[50],b[50],c[100],m,n,i,j,k;
printf("enter the two array size\n");
scanf("%d %d",&m,&n);

printf("enter the first sorted array:\n");
for(i=0;i<m;i++)
{
	scanf("%d",&a[i]);
}

printf("enter the second sorted array:\n");
for(j=0;j<n;j++)
{
	scanf("%d",&b[j]);
}

for(i=0,j=0,k=0;k<(m+n);k++)
{
if(a[i]<b[j])
		c[k]=a[i++];
else
		c[k]=b[j++];

}

for(k=0;k<(m+n);k++)
{
		printf("%d\t",c[k]);
}

}




