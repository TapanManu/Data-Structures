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
    par=(struct node*)malloc(sizeof(struct node));
    if((ptr->data)!=key)
    {
        ptr1=ptr->lc;
        ptr2=ptr->rc;
        if(ptr1!=NULL)
        {   
            printf("parent data:%d\n",ptr->data);
            printf("ptr left child:%d\n",ptr1->data);
            return(searchparent(key,ptr1,ptr));
        }
        if(ptr2!=NULL)
        {
            printf("parent data:%d\n",ptr->data);
            printf("ptr right child:%d\n",ptr2->data);
            return(searchparent(key,ptr2,ptr));
        }
    }
    else if(ptr->data==key &&((parent->rc==ptr)||(parent->lc==ptr)))
    {
        printf("parent->data:%d\n",parent->data);
        return parent;   
    }
}
void delete_tree(struct node* root)
{
	struct node* ptr,*l,*new;
	int key;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr=root;
    l=(struct node*)malloc(sizeof(struct node));
	printf("enter the node in which you want to delete the data");
	scanf("%d",&key);
	l=searchparent(key,ptr,root);
    printf("\nthe parent is:%d\n",l->data);
	if(l==NULL)
	{
		printf("search is unsuccessful\n");
		return;
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
	delete_tree(root);
    printf("\npreorder traversal is:\n");
	preorder(root);
	printf("\ninorder traversal\n");
	inorder(root);
	printf("\npostorder traversal\n");
	postorder(root);
}