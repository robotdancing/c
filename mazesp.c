#include<stdio.h>
#include<stdlib.h>

typedef struct Qu
{
	int x;
	int y;
	int pre;
}Qu[100];

int front=0;
int rear=0;

void print(int cur,Qu qu)
{
	while(cur!=-1)
	{
		printf("(%d,%d),",qu[cur].x,qu[cur].y);
		cur=qu[cur].pre;
	}

}

void FindSp(int startx,int starty,int exitx,int exity,int maze[][10])
{
	Qu qu;
	int dir,ix,iy,k,find;
	rear++;
	qu[rear].x=startx;
	qu[rear].y=starty;
	qu[rear].pre=-1;
	maze[startx][starty]=4;
	while(front<=rear)
	{
		front++;
		for(dir=0;dir<4;dir++)
		{
			switch(dir)
			{
				case 0:
					ix=qu[front].x+1;
					iy=qu[front].y;
					break;
				case 1:
					ix=qu[front].x;
					iy=qu[front].y+1;
					break;
				case 2:
					ix=qu[front].x-1;
					iy=qu[front].y;
					break;
				case 3:
					ix=qu[front].x;
					iy=qu[front].y-1;
					break;
				default:
					break;
			}
			if(ix>=0&&ix<10&&iy>=0&&iy<10&&maze[ix][iy]==0&&(qu[front].pre==-1||ix!=qu[qu[front].pre].x||iy!=qu[qu[front].pre].y))
			{
				rear++;
				qu[rear].x=ix;
				qu[rear].y=iy;
				qu[rear].pre=front;
				maze[ix][iy]=4;
			}			
		}
	}
	for(k=0;k<=rear;k++)
	{
		
		if(qu[k].x==exitx&&qu[k].y==exity)
		{
			find=1;
			printf("Find a path:");
			print(k,qu);
		}
		maze[qu[k].x][qu[k].y]=0;
	}
	if(!find)
		printf("There is no path.");
	
}
int main()
{
	int maze[][10]={0,1,1,0,1,1,1,1,0,1,
			0,1,0,0,0,0,1,1,1,1,
			0,1,0,0,1,0,1,1,1,1,
			0,0,0,1,1,0,1,1,1,1,
			0,1,1,1,0,0,1,0,0,1,
			1,1,1,1,0,1,1,0,0,1,
			1,1,0,1,0,0,0,0,0,1,
			1,1,0,0,1,1,1,1,0,1,
			0,1,1,0,1,1,1,1,0,1,
			0,1,1,1,1,1,1,1,0,0
			};
	FindSp(0,0,9,9,maze);
}
