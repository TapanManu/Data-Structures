#include<stdio.h>
#include<stdlib.h>
# define max 25
int queue[max],front=-1,rear=-1;
void enqueue_rear(int ele)
{
	if((front==0 && rear==max-1)||(front==rear+1))
	{
		printf("overflow");
	}
	else
	{
		if(front==-1)
			front=rear=0;
		else if(rear==max-1)
			rear=0;
		else
		{
		rear=rear+1;
		queue[rear]=ele;
		}
	}
}
void enqueue_front(int ele)
{
	if((front==0 && rear==max-1)||(front==rear+1))
	{
		printf("overflow");
	}
	else
	{
		if(front==-1)
			front=rear=0;
		else if(front==0)
			front=max-1;
		else
		{
			front=front-1;
			queue[front]=ele;
		}
	}
}
int dequeue_rear()
{
	int x;
	if(front==-1)
	{
		printf("underflow");
		front=rear=-1;
	}
	else
	{
		rear=rear-1;
		if(rear==0)
			rear=max-1;
		else if(front==rear)
		{
			x=queue[rear];
			front=rear=-1;
			return x;
		}
		x=queue[rear];
		return x;
	}
}
int dequeue_front()
{
	int x;
	if(front==-1)
	{
		printf("underflow");
		front=rear=-1;
	}
	else
	{
		front=front+1;
		if(front==max-1)
			front=0;
		else if(front==rear)
		{
			x=queue[front];
			front=rear=-1;
			return x;
		}
		x=queue[front];
		return x;
	}
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
		printf("1.enqueue at rear\n");
		printf("2.enqueue at front\n");
		printf("3.dequeue at front\n");
		printf("4.dequeue at rear\n");
		printf("5.queue status\n");
		printf("6.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					printf("enter element");
					scanf("%d",&ele);
					enqueue_rear(ele);
					break;
				}
			case 3:
				{
					ele=dequeue_front();
					if(ele !=-1)
						printf("%d\n",ele);
					break;
				}	
			case 5:
				{
					printqueue();
					break;
				}
			case 2:
				{
					printf("enter element");
					scanf("%d",&ele);
					enqueue_front(ele);
					break;

				}	
			case 4:
				{
					ele=dequeue_rear();
					if(ele !=-1)
						printf("%d\n",ele);
					break;
				}	
			default:
				{
					ch=6;
				}

		}
	}while(ch!=6);

}
