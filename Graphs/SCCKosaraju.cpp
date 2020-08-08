// KOSARAJU ALGO

#include<bits/stdc++.h>
using namespace std;

vector<int> order;
void dfs1(vector<int> adj[],int used[],int i)
{
    if(used[i]) return;
    used[i] = 1;
    for(int j:adj[i])
        dfs1(adj,used,j);

order.push_back(i);
}
void dfs2(vector<int> trans[],int used[],int i)
{
    if(used[i]) return ;
    used[i] = 1;
    for(int j:trans[i]) dfs2(trans,used,j);
    
}
int kosaraju(int V, vector<int> adj[])
{
    // Your code here
    order.clear();
    int used[V];
    memset(used,0,sizeof(used));
    int ans = 0 ;
    vector<int> trans[V];
    for(int i = 0;i<V;i++)
        for(int j:adj[i])  trans[j].push_back(i);
    for(int i =0;i<V;i++) if(!used[i]) dfs1(adj,used,i);
    reverse(order.begin(),order.end());
    memset(used,0,sizeof(used));
    
    for(int i =0;i<V;i++)
    {
        int v = order[i];
        if(!used[v]) {dfs2(trans,used,v);ans++;}
    }
    return ans;
}
int main()
{
//formaltites
}
