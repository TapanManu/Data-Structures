#include<stdio.h>
void print_matrix(int b[][3],int count)
{
int i,j;
for(i=0;i<=count;i++)
{printf("\n");
	for(j=0;j<3;j++)
	{
			printf("%d\t",b[i][j]);
	}
}
}
void matrix(int a[][10],int m,int n)
{
int i=0,j=0,k=0,count=0;
int b[20][3];
b[k][0]=m;
b[k][1]=n;
k++;
for(i=0;i<m;i++)
{
	for(j=0;j<n;j++)
	{
			if(a[i][j]!=0)
			{	count++;
					b[k][0]=i;
					b[k][1]=j;
					b[k][2]=a[i][j];
					k++;
			}
	}
}
b[0][2]=count;
print_matrix(b,count);
}
void transpose_sparse(int a[][3],int count)
{
in k=1,m=a[0][2]; 
if(count==0)
	{
		printf("there are no non zero elements");
	return;
	}
b[0][1]=a[0][0];
b[0][0]=a[0][1];
b[0][2]=a[0][2];
for(i=0;i<(a[0][1]);i++)
{
	for(j=0;j<(a[0][2]);j++)
	{
		if(i==a[j][i])
		{
			b[k][0]=a[j][1];
			b[k][1]=a[j][0];
			b[k][2]=a[j][2];
			k++;
		}
	}
}
print_matrix(b,m);
}
void main()
{


