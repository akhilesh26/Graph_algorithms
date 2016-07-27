#include<bits/stdc++.h>
using namespace std;
#define m 100
int adj[m][m],s,d,nv,ne;
void floyed()
{
	int from,via,dest;
	for(via=1;via<=nv;via++)
	{
		for(from=1;from<=nv;from++)
		{
			for(dest=1;dest<=nv;dest++)
			{
				if(adj[from][dest]>adj[from][via]+adj[via][dest])
					adj[from][dest]=adj[from][via]+adj[via][dest];
			}
		}
	}
}
int main()
{
	int u,v,wt,i,j;
	cin>>nv>>ne;
	for(i=1;i<=nv;i++)
	{
		for(j=1;j<=nv;j++)
		{
			adj[i][j]=m;
			adj[j][i]=m;
		}
	}
	for(i=1;i<=ne;i++)
	{
		cin>>u>>v>>wt;
		adj[u][v]=wt;
		adj[v][u]=wt;
	}
	
	floyed();
	cout<<"src  dest\n";
	for(i=1;i<5;i++)
	{
		cin>>s>>d;
		cout<<adj[s][d]<<endl;
	}
	
}