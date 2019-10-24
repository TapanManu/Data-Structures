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
void transpose_sparse(int a[][10],int m,int n)
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
printf("\n\tthe three column representation of original matrix\n");
print_matrix(b,count);
k=0;
int l=b[0][2],c[20][3]; 
if(count==0)
	{
		printf("there are no non zero elements");
	return;
	}
c[k][1]=b[0][0];
c[k][0]=b[0][1];
c[k][2]=l;
k++;
printf("%d",c[0][0]);
printf("%d",c[0][1]);
printf("%d",c[0][2]);

for(i=0;i<(b[0][1]);i++)
{	
	for(j=1;j<=l;j++)
	{	
		if(i==b[j][1])
		{

			c[k][0]=b[j][1];
			c[k][1]=b[j][0];
			c[k][2]=b[j][2];
			k++;
		}
	}
}
printf("\n\tthe three column representation of transposed matrix\n");
print_matrix(c,l);

}
void main()
{
int a[10][10],m,n,i,j,count=0,d=0,choice;
printf("enter the sizes");
scanf("%d %d",&m,&n);
for(i=0;i<m;i++)
{
	for(j=0;j<n;j++)
	{
			scanf("%d",&a[i][j]);
	}
}
do
{
printf("1.Three column representation");
printf("2.Transpose");
printf("select your choice(1-2)");
scanf("%d",&choice);
switch(choice)
{
		case 1:
						{
							for(i=0;i<m;i++)
								for(j=0;j<n;j++)
									if(a[i][j]!=0)
											count++;
						if(count<=(m*n)/2)
						{
							printf("\tmatrix is sparse\n");
							printf("the three column representation of sparse matrix ");
							matrix(a,m,n);
						}		
						else
						{
							printf("matrix is not sparse");
						}
						}
						break;
	case 2:
						{
						
							for(i=0;i<m;i++)
								for(j=0;j<n;j++)
									if(a[i][j]!=0)
											count++;
						if(count<=(m*n)/2)
						{
							printf("\tmatrix is sparse\n");
						}		
						else
						{
							printf("matrix is not sparse");
						}
						
						transpose_sparse(a,m,n);							
						}
						break;
}
printf("press 0 for exit 1 for continue");
scanf("%d",&d);
}while(d==1);
}



