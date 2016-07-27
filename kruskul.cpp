#include<bits/stdc++.h>
using namespace std;
# define max 100
class edge
{
	public:
		int u,v,wt;
};
int n,c=0,vertex;
edge graph[max];
edge tree[max];
int compfunc(const edge e1,const edge e2)
{
	return e1.wt<e2.wt;
}
void make_tree()
{
	int father[max];
	for(int i=0;i<vertex;i++)
	{
		father[i]=-1;
	}
	int u,v,root_v,root_u;
	for(int i=0;i<n;i++)
	{
		edge temp;
		temp=graph[i];
		u=temp.u;
		v=temp.v;
		while(u!=-1)
		{
			root_u=u;
			u=father[u];
		}
		while(v!=-1)
		{
			root_v=v;
			v=father[v];
		}
		if(root_v!=root_u)
		{	
			c++;
			tree[c]=temp;
			father[root_v]=root_u;
		}

	}

}
int main()
{
	cout<<"how many edges \n";
	int i;
	cin>>n;
	cin>>vertex;
	for( i=0;i<n;i++)
	{
		
		cin>>graph[i].u;
		cin>>graph[i].v;
		cin>>graph[i].wt;
	}
	
	sort(graph,graph+n,compfunc);
	make_tree();
	for(i=1;i<=c;i++)
	{
		printf("%d-->%d =%d\n",tree[i].u,tree[i].v,tree[i].wt);
	}
}