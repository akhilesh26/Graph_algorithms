#include<bits/stdc++.h>
using namespace std;
class edge{
	public:
			int u,v,wt;
};
edge graph[100];
#define m 100000
int ne,nv,s,d,distence[100],i,j;
void bellman()
{
	distence[s]=0;
	for(i=1;i<nv;i++)
	{
		for(j=1;j<=ne;j++)
		{
			int u,v,wt;
			u=graph[j].u;
			v=graph[j].v;
			wt=graph[j].wt;
			printf("edge %d -> %d\n", u, v);
			if(distence[v]>distence[u]+wt)
			{
				distence[v]=distence[u]+wt;
				cout<<u<<"->"<<v<< " "<<distence[v]<<endl;
			}
			// for undirected graph
			if(distence[u]>distence[v]+wt)
			{
				distence[u]=distence[v]+wt;
				cout<<v<<"->"<<u<<" "<<distence[u]<<endl;
			}
		}
	}
	for(j=1;j<=ne;j++)
		{
			int u,v,wt;
			u=graph[i].u;
			v=graph[i].v;
			wt=graph[i].wt;
			if(distence[v]>distence[u]+wt)
			{
				cout<<"nigative cycle detected\n";
				break;
			}
		}

		
}
int main()
{
	
	cin>>nv>>ne;
	for(i=1;i<=ne;i++)
	{
		cin>>graph[i].u>>graph[i].v>>graph[i].wt;
	}
	for(i=1;i<=nv;i++)
		distence[i]=m;
	cout<<"Enter source\n";
	cin>>s;
	bellman();
	cout<<"Enter distination\n";
	cin>>d;
	cout<<"minmum distence :"<<distence[d]<<endl;
}