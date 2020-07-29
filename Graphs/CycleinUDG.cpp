// very similar to finding cycle in Directed Graph
// in this just the edge connecting parent and child is ignored

int dfs(int i,vector<int> adj[],int used[],int pr[])
{
   used[i] =1 ;
   for(int v:adj[i])
   {  if(pr[i] == v) continue;
        pr[v] = i;
        if(used[v] == 1) return 1;
        else if(used[v]==0) {
            if(dfs(v,adj,used,pr)) return 1;
        }
       
   }
   used[i] = 2;
   return 0;
}
bool isCyclic(int v, vector<int> adj[])
{
    // Your code here
    int used[v] ,pr[v];
    memset(used,0,sizeof(used));
  memset(pr,-1,sizeof(pr));
  
    int ok = 0;
    for(int i =0 ;i<v;i++)
    if(!used[i])
    ok = ok || dfs(i,adj,used);
    return ok;
    
}

int main()
{
//input graph edges in vector<int> adj[]
// initialize used/color array with 0  
cout<<isCylic(v,adj[]); // 1 - cycle present 0 - not present 
}
