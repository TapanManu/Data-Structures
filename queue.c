#include<stdio.h>
#include<stdlib.h>
# define max 25
int queue[max],front=-1,rear=-1;
void enqueue(int ele)
{
	if(rear==max-1)
	{
		printf("overflow");
	}
	else
	{
		rear=rear+1;
		queue[rear]=ele;
	}
}
int dequeue()
{
	int x;
	if(front==rear)
	{
		printf("underflow");
		front=rear=-1;
	}
	else
	{
		front=front+1;
		x=queue[front];
		return x;
	}
}
void main()
{
	int x,y,z;
	printf("enter the elements");
	scanf("%d",&x);
	scanf("%d",&y);
	enqueue(x);
	enqueue(y);
	z=dequeue();
	printf("%d",z);
	z=dequeue();
	printf("%d",z);
	z=dequeue()
}