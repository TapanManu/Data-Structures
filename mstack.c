#include<stdio.h>
void push(int stack[],int top[],int ele,int max[],int i)
{
	if(top[i]==max[i])
	{
		printf("overflow\n");
		return;
	}
	stack[++top[i]]=ele;
}
void pop(int stack[],int top[],int min[],int i)
{
	if(top[i]==min[i])
	{
		printf("underflow\n");
		return;
	}
	printf("the popped out element from stack is%d\n",stack[top[i]--]);
}
void display(int stack[],int top[],int i,int min[],int max[])
{
	int j;
	printf("the stack displayed is %d\n",i+1);
	for(j=top[i];j>min[i];j--)
	{
		printf("	%d\n",stack[j]);
	}
}
void  main()
{
	int stack[100],i,ele,max[50],min[50],n,m,ch,choice,size,top[50],s;
	printf("the maximum size alloted:");
	scanf("%d",&n);
	printf("the number of stacks:");
	scanf("%d",&m);
	size=n/m;
	printf("size of each stack:%d\n",size);
	min[0]=-1;
	for(i=1;i<m;i++)
	{
		min[i]=min[i-1]+size;
	}
	for(i=0;i<n-1;i++)
	{
		max[i]=min[i]+size;
	}
	for(i=0;i<n;i++)
	{
		top[i]=min[i];
	}
	do{
		printf("1.Push\n2.Pop\n3.Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				printf("enter the stack you want to push\n");
				scanf("%d",&s);
				printf("enter the element you want to push\n");
				scanf("%d",&ele);
				push(stack,top,ele,max,s-1);

		}
			break;
			case 2:
			{
				printf("enter the stack you want to pop\n");
				scanf("%d",&s);
				pop(stack,top,min,s-1);
			}
			break;
			case 3:
			{
				printf("enter the stack you want to display\n");
				scanf("%d",&s);
				display(stack,top,s-1,min,max);
			}
	}
	printf("do you want to continue?\n");
	scanf("%d",&ch);

}while(ch==1);
}