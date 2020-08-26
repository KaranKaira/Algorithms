#include <iostream>
#include<vector>
using namespace std;
bool issafe(int v,vector<int> adj[],int color[],int c)
{
    int h = adj[v].size();
    for(int k=0;k<h;k++)
    {
        if( color[adj[v][k]]== c) return false;
    }
    return true;
}
bool graphUtil(vector<int> adj[],int n,int m,int v,int color[])
{
    if(v==n) return true;
    
    for(int c=1;c<=m;c++)
    {
        if(issafe(v,adj,color,c))
        {
            color[v] = c;
            if(graphUtil(adj,n,m,v+1,color)) return true;
            color[v] = 0;
        }
    }
    return false;
}
bool solve(vector<int> adj[],int n,int m)
{
    int color[n];
    for(int i=0;i<n;i++) color[i] = 0;
    return graphUtil(adj,n,m,0,color);
}
int main() {
	int t;cin>>t;while(t--)
	{
	    int n,m,e;cin>>n>>m>>e;
	    vector<int> adj[1+n];
	    for(int i=0;i<e;i++)
	    {
	        int a,b;cin>>a>>b;
	        a--;b--;
	        adj[a].push_back(b);
	        adj[b].push_back(a);
	    }
	    int used[n] = {0};
	    cout<<solve(adj, n, m)<<endl;
	   
	}
	return 0;
}
