#include<stdio.h>
#define max 50
int tree[50],k;
int flag=0;
void create_tree(int i)
{
	int true=1,ele,lc,rc;
	if(i==max)
	{
		printf("memory exhausted\n");
		return;
	}
	
	printf("enter data into %d\n",i);
	scanf("%d",&ele);
	tree[i]=ele;
		printf("do you want to insert at left of %d node?(1/0)\n",i);
		scanf("%d",&lc);
		if(lc)
			create_tree(2*i);
		else
			printf("no insertion at left node\n");
		printf("do you want to insert at right of %d node?(1/0)\n",i);
		scanf("%d",&rc);
		if(rc)
			create_tree(2*i+1);
		else
			printf("no insertion at right node\n");
	if(lc==0 && rc==0)
		k=i;
}
void print_tree()
{int i;
	for(i=1;i<=k;i++)
		if(tree[i]!=NULL)
			printf("%d\t",tree[i]);
		else
			printf("-\t");
}
void inorder(int i)
{
	if(tree[i]==NULL)
		return;
	inorder(2*i);
	printf("%d\t",tree[i]);
	inorder(2*i+1);
}
int search_node(int i,int ele)
{
	int j;
	while(tree[i]!=ele && i<=k)
		i++;
	if(tree[i]==ele)
		return i;
	else
		return -1;
}
void insert(int ele)
{
	int key,l,choice;
	printf("enter the postition into which you want to insert your node");
	scanf("%d",&key);
	l=search_node(1,key);
	if(l==-1)
		{
			printf("no matching node\n");
			return;
		}	
	if(tree[2*l]==NULL || tree[2*l+1]==	NULL)
	{
		printf("choose the postition you want to insert data(left=1/right=0)\n");
		scanf("%d",&choice);
		printf("enter the element\n");
		scanf("%d",&ele);
		switch(choice)
		{
			case 1:
			{
				if(tree[2*l]==NULL)
					tree[2*l]=ele;
				else
					printf("no insertion at left\n");
				break;	 
			}
			case 0:
			{
				if(tree[2*l+1]==NULL)
					tree[2*l+1]=ele;
				else
					printf("no insertion at right\n"); 
				break;
			}
			default:
				printf("no insertion\n");
		}

	}
	else
		printf("node is not leaf node\n");
}
void delete(int key)
{
	int l;
	//printf("enter the node you want to delete\n");
	//scanf("%d",&key);
	l=search_node(1,key);
	if(l==-1)
		{
			printf("no matching node\n");
			return;
		}	
	if(tree[2*l]==NULL && tree[2*l+1]==	NULL)
	{
		tree[l]=NULL;
	}
	else
		printf("node is not leaf node");
}
void main()
{
	printf("enter data into tree(max size =50)\n");
	create_tree(1);
	print_tree();
	printf("\n");
	inorder(1);
	printf("enter the element you want to insert\n");
	insert(ele);
	inorder(1);
	printf("enter the element you want to delete\n");
	delete(ele);
	printf("\n");
	inorder(1);
}