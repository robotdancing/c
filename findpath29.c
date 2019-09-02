#ifndef FINDPATH_C
#define FINDPATH_C
#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
	int value;
	struct node* lchild;
	struct node* rchild;
}node1;
typedef node1* Tree;
typedef struct stack
{
	Tree *base;
	Tree *top;
}stack_t;

void InitStack(stack_t *s)
{
	s->base=(Tree*)malloc(100*sizeof(node1));
	s->top=s->base;
}

void Push_s(stack_t *s,Tree e)
{
	*(s->top)=e;
	(s->top)++;
}

void Pop_s(stack_t *s, Tree *e)
{
	(s->top)--;
	*e=*(s->top);
}

int EmptyStack(stack_t s)
{
	return (s.top==s.base)?1:0;
}

int Depth(Tree t)
{
	int LD,RD;
	if(t==NULL)
		return 0;
	else
	{
		LD=Depth(t->lchild);
		RD=Depth(t->rchild);
		return LD>RD?(LD+1):(RD+1);
	}		
}

void FindPath(Tree t,int target)
{
	stack_t s;
	Tree cur,lastvisited,*tmp;
	int sum,depth,*path;
	cur=t;
	sum=0;
	lastvisited=NULL;
	depth=Depth(t);
	path=(int*)malloc(depth*sizeof(int));
	InitStack(&s);
	while(cur)
	{
		Push_s(&s,cur);
		sum+=cur->value;
		cur=cur->lchild;
	}
	while(!EmptyStack(s))
	{
		Pop_s(&s,&cur);
		sum-=cur->value;
		if(lastvisited==cur->rchild||cur->rchild==NULL)
		{	
			lastvisited=cur;
			if(cur->lchild==NULL&&cur->rchild==NULL&&(sum+cur->value)==target)	
			{
			
				for(tmp=s.base;tmp<s.top+1;tmp++)
				{
					printf("%d -> ",(*tmp)->value);
				}
			//	path[i]=cur->value;
			//	return path;
				printf("\n");
			}
		}
		else
		{
			Push_s(&s,cur);
			sum+=cur->value;
			cur=cur->rchild;
			while(cur)
			{
				Push_s(&s,cur);
				sum+=cur->value;
				cur=cur->lchild;
			}
		}
	}
//	return NULL;
}

void CreateTree(Tree *t)
{
	int ch;
	scanf("%d",&ch);
	if(ch!=0)
	{
		*t=(Tree)malloc(sizeof(node1));
		if(!(*t))
			exit(0);
		(*t)->value=ch;
		CreateTree(&((*t)->lchild));
		CreateTree(&((*t)->rchild));
	}
	else
		*t=NULL;
}

int main()
{
	Tree t;
	int i,j,depth,*path;
	CreateTree(&t);
//	depth=Depth(t);
	FindPath(t,17);
/*	if(path!=NULL)
	{	
		for(i=0;i<depth;i++)
			printf("%d -> ",path[i]);
	}
	else
		printf("No path");	
*/	printf("\n");
}
#endif
