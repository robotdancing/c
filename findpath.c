#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct node
{
	int value;
	struct node* lchild;
	struct node* rchild;
}node;
typedef node* BTree;
typedef struct stack
{
	BTree *base;
	BTree *top;
}stack;

void InitBT(BTree *T)
{
	*T=NULL;
}
void CreateBT(BTree *T)
{
	int ch;
	scanf("%d",&ch);
	if(ch!=0)
	{
		*T=(BTree)malloc(sizeof(node));
		if(!*T)
			exit(0);
		(*T)->value=ch;
		CreateBT(&((*T)->lchild));
		CreateBT(&((*T)->rchild));
	}
	else
		*T=NULL;
}

void InitStack(stack *s)
{
	s->base=(BTree *)malloc(MAX*sizeof(BTree));
	s->top=s->base;
}

void Push(stack *s,BTree e)
{
	*(s->top)=e;
	(s->top)++;
}

void Pop(stack *s,BTree *e)
{
	if(s->base==s->top)
		exit(0);
	(s->top)--;
	*e=*(s->top);
}

int EmptyStack(stack s)
{
	return s.base==s.top?1:0;
}

void FindPath(BTree T,int n)
{
	int sum;
	BTree *q;
	BTree p,lastvisited;
	p=T;
	sum=0;
	stack s;
	InitStack(&s);
	while(p)
	{
		Push(&s,p);
		sum+=p->value;
		p=p->lchild;
	}
	while(!EmptyStack(s))
	{
		Pop(&s,&p);
		sum-=p->value;
		if(p->rchild==NULL||lastvisited==p->rchild)
		{
								
			if(p->lchild==NULL&&p->rchild==NULL&&sum+(p->value)==n)
			{	
				q=s.base;
				do
				{
					printf("%d,",(*q)->value);
					q++;
				}while(q!=s.top+1);
				printf("\n");	
			}
			lastvisited=p;
			
		}
		else
		{
			Push(&s,p);
			sum+=p->value;
			p=p->rchild;
			while(p)
			{
				Push(&s,p);
				sum+=p->value;
				p=p->lchild;
				
			}
		}
			
	}
}

int main()
{
	BTree T;
	InitBT(&T);
	CreateBT(&T);
	FindPath(T,17);	
	return 1;
}
