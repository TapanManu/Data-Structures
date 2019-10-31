#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* lc;
	struct node* rc;
};
struct node*ptr,*root;
void preorder(struct node* ptr)
{
	if(ptr!=NULL)
	{
		printf("%d",ptr->data);
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
		printf("%d",ptr->data);
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
		printf("%d",ptr->data);	
	}	
	else
	{
		return ;
	}
} 
struct node* searchparent(int key,struct node* ptr,struct node* parent)
{   
    struct node*ptr1,*ptr2,*par;;
    ptr1=(struct node*)malloc(sizeof(struct node));
    ptr2=(struct node*)malloc(sizeof(struct node));
    printf("parent data:%d\n",parent->data);
    if((ptr->data)!=key)
    {
        ptr1=ptr->lc;
        ptr2=ptr->rc;
        if(ptr1!=NULL)
        {   printf("hi1");
            printf("parent data:%d\n",ptr->data);
            printf("ptr left child:%d\n",ptr1->data);
            par=searchparent(key,ptr1,ptr);
            if(par->data==key)
            {
                return par;
            }
        }
        if(ptr2!=NULL)
        {
            printf("parent data:%d\n",ptr->data);
            printf("ptr right child:%d\n",ptr2->data);
            par=searchparent(key,ptr2,ptr);
            if(par->data==key)
            {
                return par;
            }
        }
    }
    else if(ptr->data==key)
    {
        printf("hi3\n");
        return ptr;   
    }
}
void insert_tree(struct node* root)
{
	struct node* ptr,*l,*new;
	int opt=1,key;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr=root;
	new=(struct node*)malloc(sizeof(struct node));
    l=(struct node*)malloc(sizeof(struct node));
	printf("enter the node in which you want to insert the data");
	scanf("%d",&key);
	l=searchparent(key,ptr,root);
	if(l==NULL)
	{
		printf("search is unsuccessful\n");
		return;
	}
		if((l->lc==NULL)||(l->rc==NULL))
		{
			printf("choose to left(1) or right(0)");
			scanf("%d",&opt);
			if (opt==1)
			{
				if(l->lc==NULL)
				{
					l->lc=new;
					printf("data to be inserted\n");
					scanf("%d",&(new->data));
					new->lc=NULL;
					new->rc=NULL;
				}
				else
					printf("cannot insert\n");
			}
			else if(opt==0)
			{
				if(l->rc==NULL)
				{
					l->rc=new;
					printf("data to be inserted\n");
					scanf("%d",&(new->data));
					new->lc=NULL;
					new->rc=NULL;
				}	
				else
					printf("cannot insert\n");
			}
		}	
		else
		{
			printf("insertion not possible");
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
	int count=1;
	root=(struct node*)malloc(sizeof(struct node));
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
	insert_tree(root);
    printf("\npreorder traversal is:\n");
	preorder(root);
	printf("\ninorder traversal\n");
	inorder(root);
	printf("\npostorder traversal\n");
	postorder(root);
}