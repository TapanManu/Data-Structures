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
void sum(int x[][10],int y[][10],int m,int n)
{
int i=0,j=0,k=0,count=0,t1,t2;
int a[20][3],b[20][3],c[40][3];
a[k][0]=m;
a[k][1]=n;
k++;
for(i=0;i<m;i++)
{
	for(j=0;j<n;j++)
	{
			if(x[i][j]!=0)
			{	count++;
					a[k][0]=i;
					a[k][1]=j;
					a[k][2]=x[i][j];
					k++;
			}
	}
}
a[0][2]=count;
t1=a[0][2];
printf("three column representation of first matrix");
print_matrix(a,count);
count=0,k=0;
b[k][0]=m;
b[k][1]=n;
k++;
for(i=0;i<m;i++)
{
	for(j=0;j<n;j++)
	{
			if(y[i][j]!=0)
			{	count++;
					b[k][0]=i;
					b[k][1]=j;
					b[k][2]=y[i][j];
					k++;
			}
	}
}
b[0][2]=count;
t2=b[0][2];
printf("\n\tthree column representation of second matrix\n");
print_matrix(b,count);
if((a[0][0]!=b[0][0])||(a[0][1]!=b[0][1]))
{
printf("\n\tmatrices cannot be added\n");
return;
}
c[0][0]=a[0][0],c[0][1]=a[0][1];
k=1,m=1,n=1;
while(m<=t1 && n<=t2)
{
if(a[m][0]<b[n][0])
{	
		c[k][0]=a[m][0];
		c[k][1]=a[m][1];
		c[k][2]=a[m][2];
		k++,m++;
}
else if(a[m][0]>b[n][0])
{	
		c[k][0]=b[n][0];
		c[k][1]=b[n][1];
		c[k][2]=b[n][2];
		k++,n++;
}
else if(a[m][1]<b[n][1])
{	
		c[k][0]=a[m][0];
		c[k][1]=a[m][1];
		c[k][2]=a[m][2];
		k++,m++;
}
else if(a[m][1]>b[n][1])
{	
		c[k][0]=b[m][0];
		c[k][1]=b[m][1];
		c[k][2]=b[m][2];
		k++,n++;
}
else
{
		c[k][0]=a[m][0];
		c[k][1]=a[m][1];
		c[k][2]=a[m][2]+b[n][2];
		k++,m++,n++;
}
}
while(m<=t1)
{
c[k][0]=a[m][0];
c[k][1]=a[m][1];
c[k][2]=a[m][2];
k++,m++;
}
while(n<=t2)
{
c[k][0]=b[n][0];
c[k][1]=b[n][1];
c[k][2]=b[n][2];
k++,n++;
}
c[0][2]=k-1;
printf("\n\tthree column representation of sum matrix\n");
print_matrix(c,k-1);
}
void main()
{
int a[10][10],b[10][10],m,n,p,q,i,j,count=0,d=0,choice;
printf("\n\tenter the sizes of first matrix");
scanf("%d %d",&m,&n);
for(i=0;i<m;i++)
{
	for(j=0;j<n;j++)
	{
			scanf("%d",&a[i][j]);
	}
}
printf("\n\tenter the sizes of second matrix");
scanf("%d %d",&p,&q);
for(i=0;i<p;i++)
{
	for(j=0;j<q;j++)
	{
			scanf("%d",&b[i][j]);
	}
}
if(m==p && n==q)
sum(a,b,m,n);
else
printf("\n\tmatrices cannot be added\n");
}

