#ifndef DEEPCOPY_C
#define DEEPCOPY_C
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int value;
	struct node *next;
	struct node *saved;
}node1;

typedef node1* Node; 

struct node* DeepCopy(struct node head)
{
	Node list_node,copy_list_node,tmp;
	list_node=head.next;
	while(list_node!=NULL)
	{
		copy_list_node=(Node)malloc(sizeof(node1));
		copy_list_node->value=list_node->value;
		copy_list_node->next=list_node->next;
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
	(*L)=(Node)malloc(sizeof(node1));
	(*L)->next=NULL;
	Node p,q;
	int i;
	for(q=(*L),i=0;i<n;i++)
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
	Node tmp,h,h_copy;
	CreateList(&h,10);
	tmp=h->next;
	while(tmp)
	{
		printf("value = %d, saved_value=%d \n",tmp->value,tmp->saved->value);
		tmp=tmp->next;
	}
	printf("\n\n\n");
	h_copy=DeepCopy(*h);
	while(h_copy)
	{
		printf("copy_value = %d, copy_saved_value=%d \n",h_copy->value,h_copy->saved->value);
		h_copy=h_copy->next;
	}
	return 1;
}
#endif
