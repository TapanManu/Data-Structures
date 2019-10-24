#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
//global declaration
char stack[15];
int top=-1,size=15;


void push(int item)
{
	if(top==size-1)
	{
				printf("overflow\n");
	}
	stack[++top]=item;
	printf("%c\n",item);
}
int pop()
{
int item;

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

void evaluate_exp(char* exp)
{
int x,y,result,item;
int j=0;
int i;
for(i=0;exp[i]!='\0';i++)
{
                item=exp[i];
				if(isdigit(exp[i]))
				{
                    item=(int)exp[i]-48;
					push(item);
				}
				else if(is_operator(item)==1)
				{
					y=pop();
					x=pop();
                    switch(item)
                    {
                        case '*':
                        {
                            
                            push((int)(x*y));
                            break;
                        }
                        case '+':
                        {
                            push((int)(x+y));
                            break;
                        }
                        case '^':
                        {
                            
                            push((int)(pow(x,y)));
                            break;
                        }
                        case '-':
                        {
                            
                            push((int)(x-y));
                            break;
                        }
                        case '/':
                        {
                            
                            push((int)(x/y));
                            break;
                        }
                        default:
                        printf("wrong input\n");
                    }
				}
				else
				{
					printf("wrong operation");
				}
}
result=pop();
printf("the result is:%d",result);
}
void main()
{
	char exp[25];
	printf("enter your postfix expression\n");
	scanf("%s",exp);
	evaluate_exp(exp);
}
 



