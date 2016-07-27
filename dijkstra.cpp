#include<bits/stdc++.h>
using namespace std;
# define max 100000;
int e,s,n;
int distence[100];
int done[100];
int adj[100][100];
int parent[100];
void dijkstra(int src)
{
	int i,c=1,min,v_min;
	for(i=1;i<=n;i++)
	{
		distence[i]=max;
		done[i]=0;
	}
	distence[src]=0;
	while(c<=n)
	{
		min=max;
		for(i=1;i<=n;i++)
		{
			if(done[i]==0&&distence[i]<min)
			{
				min=distence[i];
				v_min=i;
			}
		}
		//cout<<min<<endl;
		for(i=1;i<=n;i++)
		{
			if(adj[v_min][i]>0&&done[i]==0&&distence[i]>(distence[v_min]+adj[v_min][i]))
			{
				distence[i]=distence[v_min]+adj[v_min][i];
				//cout<<v_min<<" --->"<<i<<" = "<<distence[i]<<endl;
				//parent[i]=v_min;
			}
		}
		done[v_min]=1;
		c++;

	}

}
int main()
{
	int u,v,wt;
	cin>>n;
	cout<<"no of edge\n";
	cin>>e;
	for(int i=1;i<=e;i++)
	{
		cin>>u>>v>>wt;
		adj[u][v]=wt;
		adj[v][u]=wt;
	}
	cout<<"enter source vertex \n";
	cin>>s;
	dijkstra(s);
	int d;
	cout<<"Enter destination\n";
	cin>>d;
	cout<<distence[d]<<endl;
}