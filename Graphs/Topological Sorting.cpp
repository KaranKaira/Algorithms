//Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv, 
//vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.


#include <bits/stdc++.h>
using namespace std;
vector<bool> used(200000); // Used to keep track of already visited nodes.
vector<int> adj[200000];  // adjancency list
stack<int> s;
void addEdge(int u ,int v)
{
	adj[u].push_back(v);
}

void topologiclsort(int src)
{
used[src] = true;
for(int i :adj[src])
if(!used[i]) topologiclsort(i);
s.push(src);
}

		

void solve()
{

 	addEdge(5, 2); 
    addEdge(5, 0); 
    addEdge(4, 0); 
    addEdge(4, 1); 
    addEdge(2, 3); 
    addEdge(3, 1); 
    for(int i =1 ;i<=5;i++)
    	if(used[i]==false)
    		topologiclsort(i);

    	// priting the Topological Order
    	while(s.empty()==false)
    	{
    		int p = s.top();
    		s.pop();
    		cout<<p << " ";	
    	}

}
int main()
{
	solve();
	return 0;
}
