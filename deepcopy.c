#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node *next;
	struct node *saved;
}node1;

typedef node1* Node;

struct node * DeepCopy(struct node head)
{
	Node list_node,copy_list_node,tmp;
	list_node=head.next;
	while(list_node!=NULL)
	{
		copy_list_node=(Node)malloc(sizeof(node1));
		copy_list_node->value=list_node->value;
		copy_list_node->next=list_node->next;
		copy_list_node->saved=NULL;	
		list_node->next=copy_list_node;
		list_node=copy_list_node->next;
	}
	list_node=head.next;
	copy_list_node=tmp=list_node->next;
	while(list_node!=NULL&&copy_list_node!=NULL)
	{
		if(copy_list_node->next!=NULL)
		{
			copy_list_node->saved=list_node->saved->next;
			list_node->next=list_node->next->next;
			copy_list_node->next=copy_list_node->next->next;
			list_node=list_node->next;
			copy_list_node=copy_list_node->next;
		}
		else
		{
			copy_list_node->saved=list_node->saved->next;
			list_node->next=NULL;
			list_node=list_node->next;
			copy_list_node=copy_list_node->next;
		}
	}
	return tmp;
}
void CreateList(Node *L,int n)
{
	*L=(Node)malloc(sizeof(node1));
	Node p,q,tmp;
	int i;
	(*L)->next=NULL;
	for(i=0,q=*L;i<n;i++)
	{
		p=(Node)malloc(sizeof(node1));
		p->value=i;
		q->next=p;
		p->saved=p;
		q=q->next;
	}
	q->next=NULL;
}
int main()
{
	int n=10;
	Node he,p;
	CreateList(&he,n);
	p=he->next;
	while(p)
	{
		printf("list is:%d,and saved value is %d\n",p->value,p->saved->value);
		p=p->next;
	}
	p=DeepCopy(*he);
	while(p)
	{
		printf("copy list is:%d,and saved value is %d\n",p->value,p->saved->value);
		p=p->next;
	}
}

