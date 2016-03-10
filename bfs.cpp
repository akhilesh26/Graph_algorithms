#include<bits/stdc++.h>
# define initial 1
# define waiting 2
# define visited 3
# define max 100
int adj[max][max];
int queue[max];
int state[max];
int parent[max];
int depth[max];
int n, rear=-1,front=-1;
void insert(int value)
{
	if(rear==max)
	{
		printf("overflow\n");
	}
	else
	{
		if(front==-1)
			front=0;
		queue[++rear]=value;
	}
//	printf("value inserted\n");
}
int del()
{
	//printf("%d  %d\n",front,rear );
	if(front==-1||front>rear)
	{
		printf("underflow\n");
		exit(1);
	}
	//printf("deleted\n");
	return queue[front++];
}
int isempty()
{
	if(front==-1||front>rear)
		return 1;
	else
		return 0;
}
void create()
{
	int e,x,y;
	printf("Enter the no of vertex and edges\n");
	scanf("%d%d",&n,&e);
	for(int i=1;i<=e;i++)
	{
		scanf("%d%d",&x,&y);
		adj[x][y]=1;
		adj[y][x]=1;
	}
}
void bfs(int v)
{
	//printf("bfs\n");
	state[v]=waiting;
	depth[v]=0;
	parent[v]=-1;
	insert(v);
	//printf("%d\n",isempty() );
	while(!isempty())
	{
		v=del();
		printf("vertex:%d  parent:%d  depth:%d\n",v,parent[v],depth[v]);
		state[v]=visited;
		for(int i=1;i<=n;i++)
		{
			if(adj[v][i]==1&&state[i]==initial)
			{
				insert(i);
				state[i]=waiting;
				depth[i]=depth[v]+1;
				parent[i]=v;
			}
		}
	}
}
void bfs_traverse()
{
	//printf("bfs traverse \n");
	for(int i=1;i<=n;i++)
	{
		state[i]=initial;
	}
	int v;
	printf("Enter the starting vertex\n");
	scanf("%d",&v);
	bfs(v);
}
int main(int argc, char const *argv[])
{
	/* code */
	create();
	bfs_traverse();
	return 0;
}