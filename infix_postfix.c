#include<stdio.h>
#include<ctype.h>
#include<string.h>
//global declaration
char stack[15];
int top=-1,size=15;


void push(char item)
{
	if(top==size-1)
	{
				printf("overflow\n");
	}
	stack[++top]=item;
}
char pop()
{
char item;
if(top==-1)
{
	printf("underflow");
}
else
{
item=stack[top--];
return(item);
}
}
int is_operator(char item)
{
if(item=='^'||item=='*'||item=='+'||item=='-'||item=='/')
			return 1;
else
			return 0;
}
int evaluation(char item)
{
	if(item=='^')
				return 3;
	else if(item=='*' ||item=='/')
				return 2;
	else if(item=='+' ||item=='-')
				return 1;
	else
				return 0;
}
void infix_postfix(char infix[])
{
			int i=0,j=0;
			char item,x,postfix[25];
			push('(');
			strcat(infix,")");
			item=infix[i];
			while(item!='\0')
			{
							if(item=='(')
							{
										push(item);
							}
							else if(isalpha(item)||isdigit(item))
							{
										postfix[j]=item;
										j++;
							}
							else if(is_operator(item)==1)
							{
										x=pop();
										while(is_operator(x)==1 && (evaluation(x)>=evaluation(item)))
										{
													postfix[j]=x;
													j++;
													x=pop();
										}
										push(x);
										push(item);
							}
							else if(item==')')
							{
										x=pop();
										while(x!='(')
										{
													postfix[j]=x;
													j++;
													x=pop();
										}
							}
							else
							{
										printf("invalid operation");
							}
							
							i++;
							item=infix[i];
				}
			
			printf("postfix expression is:");
			strcat(postfix,"\0");
			puts(postfix);
}


void main()
{
char infix[25];
printf("enter the infix expression");
scanf("%s",infix);
infix_postfix(infix);
}


