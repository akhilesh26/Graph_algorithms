#include<bits/stdc++.h>
# define initial 1
# define waiting 2 
# define visited 3
# define max 100
int n,e;
int timer =0,count1=0,count2=0;
int start[max];
int end[max];
int adj[max][max]={0};
int state[max];
void dfs_visit(int v)
{
	
	state[v]=waiting;
	start[v]=++timer;
	count1++;
	for(int i=1;i<=n;i++)
	{
		

		if(state[i]==initial&&adj[v][i]==1)
		{
			dfs_visit(i);
			
		}
		
		
	}
	state[v]=visited;
	end[v]=++timer;
	
}
int main()
{
	printf("Enter the number of vertex and edges\n");
	scanf("%d%d",&n,&e);
	int x,y;
	for(int i=1;i<=e;i++)
	{
		scanf("%d%d",&x,&y);
		adj[x][y]=1;
		adj[y][x]=1;
	}
	for(int i=1;i<=n;i++)
	{
		state[i]=initial;
	}
	dfs_visit(1);
	for(int i=1;i<=n;i++)
	{
		printf("vertex %d :%d / %d\n",i,start[i],end[i] );
	}
	

}