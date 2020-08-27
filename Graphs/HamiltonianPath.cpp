// Given an undirected graph  the task is to check if a Hamiltonian path is present in it or not.

#include <bits/stdc++.h>
using namespace std;
int isthereHP(vector<int> adj[],int n,int used[],int i)
{
    
    used[i] = 1;
    for(int j = 0 ; j<adj[i].size();j++)
    {
        if(used[adj[i][j]]) continue;    
        if(isthereHP(adj,n,used,adj[i][j]))
        {
            return 1;
        }
        
    }
    for(int j = 0;j<n;j++) if(used[j]==0)
    {
        used[i]=0;
        return 0;
    }
    
    return 1;
    
    
    
}
int main() {
	//code
	int t;cin>>t;while(t--)
	{
	    int n,m;cin>>n>>m;
	    vector<int> adj[n];
	    while(m--)
	    {
	        int a,b;cin>>a>>b;
	        a--,b--;
	        adj[a].push_back(b);
	        adj[b].push_back(a);
	    }
	    
	    int used[n];
	    for(int i=0;i<n;i++) used[i]=0;
	    
	    for(int i=0;i<n;i++)
	    {
	    if(isthereHP(adj,n,used,i)) {cout<<1<<endl;goto label;}
	    
	    memset(used,0,sizeof(used));
	        
	    }
	
	    cout<<0<<endl;
	    label:;
	}
	
	return 0;
}
