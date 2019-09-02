#ifndef MAZESP_C
#define	MAZESP_C
#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
	int x;
	int y;
	int pre;
}Qu[100];

void print(int k,Qu qu)
{
	int length=0;
	while(k!=-1)
	{
		printf("[%d,%d]",qu[k].x,qu[k].y);
		k=qu[k].pre;
	}
}

void MazeSp(int maze[][10],int start_x,int start_y,int end_x,int end_y)
{
	Qu qu;
	int front,rear,i,j,dir,find,k;
	front=rear=0;
	find=0;
	qu[rear].x=start_x;
	qu[rear].y=start_y;
	qu[rear].pre=-1;
	maze[start_x][start_y]=4;
	rear++;
	while(front<rear)
	{
		for(dir=0;dir<=3;dir++)
		{
			switch(dir)
			{
				case 0:
					i=qu[front].x+1;
					j=qu[front].y;
					break;
				case 1:
					i=qu[front].x;
					j=qu[front].y+1;
					break;
				case 2:
					i=qu[front].x-1;
					j=qu[front].y;
					break;
				case 3:
					i=qu[front].x;
					j=qu[front].y-1;
					break;
			}
			if(i>=0&&i<10&&j>=0&&j<10&&maze[i][j]==0&&(qu[front].pre==-1||i!=qu[qu[front].pre].x||j!=qu[qu[front].pre].y))
			{
				qu[rear].x=i;
				qu[rear].y=j;
				qu[rear].pre=front;
				maze[i][j]=4;
				rear++;
			}
		}
		front++;
	}
	for(k=0;k<rear;k++)
	{
		if(qu[k].x==end_x&&qu[k].y==end_y)
		{
			print(k,qu);
			find=1;
		}
	}
	if(find==0)
		printf("no rounte");
}

int main()
{
	int maze[][10]={
			0,1,1,0,1,1,1,1,0,1,
			0,1,0,0,0,0,1,1,1,1,
			0,1,0,0,1,0,1,1,1,1,
			0,0,0,1,1,0,1,1,1,1,
			0,1,1,1,0,0,1,0,0,1,
			1,1,1,1,0,1,1,0,0,1,
			1,1,0,1,0,0,0,0,0,1,
			1,1,0,0,1,1,1,1,0,1,
			0,1,1,0,1,1,1,1,0,1,
			0,1,1,1,1,1,1,1,0,0,
			};
	MazeSp(maze,0,0,9,9);
}
#endif
