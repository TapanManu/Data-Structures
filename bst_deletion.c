#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* lc;
	struct node* rc;
};
struct node*ptr,*root,*temp,*ptr1,*parent;
void preorder(struct node* ptr)
{
	if(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		preorder(ptr->lc);
		preorder(ptr->rc);	
	}	
	else
	{
		return ;
	}
}
void inorder(struct node* ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->lc);
		printf("%d\t",ptr->data);
		inorder(ptr->rc);	
	}	
	else
	{
		return;
	}
} 
void postorder(struct node* ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->lc);
		postorder(ptr->rc);
		printf("%d\t",ptr->data);	
	}	
	else
	{
		return ;
	}
} 
struct node*succ(struct node*ptr)
{
ptr1=(struct node*)malloc(sizeof(struct node));
ptr1=ptr->rc;
while(ptr1->lc!=NULL)
{
	ptr1=ptr1->lc;
}
return(ptr1);
}
void delete_node(struct node* root,int x)
{
int flag=0,c,item1;
parent=(struct node*)malloc(sizeof(struct node));
ptr1=(struct node*)malloc(sizeof(struct node));
temp=(struct node*)malloc(sizeof(struct node));
temp=root;
while(temp!=NULL && flag==0)
{
		if(x<temp->data)
	{
				parent=temp;
				temp=temp->lc;
	}
		else if(x>temp->data)
	{
			parent=temp;
			temp=temp->rc;
	}
	else if(x==temp->data)
	{
			flag=1;
	}
}
if(flag==0)
{
	printf("item is not present");
	return ;
}
if(temp->lc==	NULL &&temp->rc==NULL)
	c=1;
else if(temp->lc!=NULL && temp->rc !=NULL)
	c=3;
else
	c=2;
if(c==1)
{
	if(parent->lc==temp)
				parent->lc=	NULL;
	else
				parent->rc=NULL;
}
if(c==2)
{

	if(parent->lc==temp)
	{
			if(temp->lc==NULL)
			{
					parent->lc=temp->rc;
					temp=NULL;
			}
			else if(temp->rc==NULL)
			{
					printf("hi");
					parent->lc=temp->lc;
					temp=NULL;
			}
		}
	else if(parent->rc==temp)
	{
			if(temp->lc==NULL)
					{
							parent->rc=temp->rc;
							temp=NULL;
					}
			else if(temp->rc==NULL)
					{
					parent->rc=temp->lc;
					temp=NULL;
					}
	}
}
if(c==3)
{
ptr1=succ(temp);
item1=ptr1->data;
printf("item1:%d",item1);
delete_node(root,item1);
parent->data=item1;
}
}
void create_tree(struct node* ptr,int count)
{
	int ch=1,ch1=1,ch2=1;
	struct node* new,*new1;
	printf("do you want to enter data again?\n");
	scanf("%d",&ch);
	if(ch==0)
	{
		printf("no data entry\n");
		return;
	}
	printf("press 1 to insert as left child of%d\n",count);
	scanf("%d",&ch1);
	if(ch1==1 && (ptr->lc==NULL))
	{
		new=(struct node*)malloc(sizeof(struct node));
		printf("enter the data of node");
		scanf("%d",&(new->data));
		printf("ptr->data:%d",new->data);
		new->lc=NULL;
		new->rc=NULL;
		ptr->lc=new;
		create_tree(ptr->lc,2*count);
	}
	else
	{
		printf("no insertion at left node\n");
	}
	printf("press 1 to insert as right child of%d\n",count);
	scanf("%d",&ch2);
	if(ch2==1 && (ptr->rc==NULL))
	{
		new1=(struct node*)malloc(sizeof(struct node));
		printf("enter the data of node");
		scanf("%d",&(new1->data));
		printf("ptr->data:%d",new1->data);
		new1->lc=NULL;
		new1->rc=NULL;
		ptr->rc=new1;
		create_tree(ptr->rc,2*count+1);
	}
	else
	{
		printf("no insertion at right node\n");
	}
}	
void main()
{
	int count=1,x;
	root=(struct node*)malloc(sizeof(struct node));
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter data to root\n");
	scanf("%d",&(root->data));
	create_tree(root,count);
	printf("\npreorder traversal is:\n");
	preorder(root);
	printf("\ninorder traversal\n");
	inorder(root);
	printf("\npostorder traversal\n");
	postorder(root);
	printf("\n");
	printf("enter the data item you want to delete");
	scanf("%d",&x);
	delete_node(root,x);
 printf("\npreorder traversal is:\n");
	preorder(root);
	printf("\ninorder traversal\n");
	inorder(root);
	printf("\npostorder traversal\n");
	postorder(root);
}
