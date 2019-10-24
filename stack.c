#include<stdio.h>
void push(int stack[],int *top,int n,int ele)
{
if((*top)==n-1)
			{
						printf("Overflow");
						return;
			}
else
			{
						stack[++(*top)]=ele;
			}
}
int pop(int stack[],int *top,int n)
{
int ele;
if((*top)==-1)
			{
						printf("Underflow");
						return -1;
			}
else
			{
						ele=stack[*top];
						printf("the element to be pulled is %d:",stack[*top]);
						(*top)--;			
						return ele;
			}
}
void display(int stack[],int *top,int n)
{
int i;
printf("the stack is...\n");
printf("top->%d\n",stack[*top]);
for(i=(*top)-1;i>=0;i--)
{
			printf("     %d\n",stack[i]);
}
}


void retrieve_m(int stack[],int *top,int n,int m)
{
int stack2[20],top2=-1,i,ele;
if(m>(*(top)-1)
{
			printf("element not in stack");
			return;
}
i=1;
while(i<=(m-1))
{
	ele=pop(stack,top,n);
	push(stack2,&top2,20,ele);
	i++;
}
	ele=pop(stack,top,n);
printf("\n\tthe mth element is %d\n",ele);
while(top2!=-1)
{
ele=pop(stack2,&top2,20);
push(stack,top,n,ele);
}
display(stack,top,n);
}



void main()
{
int stack[20],n,choice,ch=0,top=-1,ele;
printf("enter the maximum size\n");
scanf("%d",&n);
do{
printf("select your choice\n");
printf("1.push\n");
printf("2.pop\n");\
printf("3.display\n");
printf("4.mth element");
scanf("%d",&choice);
switch(choice)
{
						case 1:
									{
														printf("enter the elements\n");
														scanf("%d",&ele);														
														push(stack,&top,n,ele);
														break;
									}
						case 2:
									{
														ele=pop(stack,&top,n);
														break;
									}
						case 3:
									{
														display(stack,&top,n);
														break;
									}
						case 4:
									{
														retrieve_m(stack,&top,n,2);
														break;
									}
						default:
														printf("wrong choice");
}
printf("do you want to continue?");
scanf("%d",&ch);
}while(ch==1);
}


