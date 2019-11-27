#include<stdio.h>
#include<stdlib.h>
# define max 5
int queue[max],front=-1,rear=-1;
void enqueue(int ele)
{
	if(((rear+1)==front) || (front==0 && rear == (max-1)))
	{
		printf("overflow\n");
	}
	else
	{
	if(front==-1)
	{
		front=0;
	}
	rear=(rear+1)%max;
	queue[rear]=ele;
	}
}
int dequeue()
{
	int x;
	if(front==-1)
	{
		printf("underflow");
		return -1;
	}
	if(front==rear)
	{
		x=queue[front];
		front=rear=-1;
		return x;
	}
	x=queue[front];
	front=(front+1) % max;
	return x;
}
void printqueue()
{
	int i;
	if(front<=rear)
	{	
	for(i=front;i<=rear;i++)
	{
		printf("%d\t",queue[i]);
	}
	}
	else
	{
		i=front;
		while(i<max)
		{
			printf("%d\t",queue[i]);
			i++;
		}
		i=0;
		while(i<=rear)
		{
			printf("%d\t",queue[i]);
			i++;
		}
	}	

}
void main()
{
	int ele,ch=1;
	do{
		printf("\nselect your choice\n");
		printf("1.enqueue\n");
		printf("2.dequeue\n");
		printf("3.queue status\n");
		printf("4.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					printf("enter element");
					scanf("%d",&ele);
					enqueue(ele);
					break;
				}
			case 2:
				{
					ele=dequeue();
					if(ele !=-1)
						printf("%d\n",ele);
					break;
				}	
			case 3:
				{
					printqueue();
					break;
				}
			default:
				{
					ch=4;
				}

		}
	}while(ch!=4);

}