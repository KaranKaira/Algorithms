// BFS APPROACH

#include <bits/stdc++.h>
using namespace std;
struct cell{
    int x,y,dist;
    cell(){}
    cell(int x,int y,int dist) : x(x),y(y),dist(dist) {}
};
bool issafe(cell cur,int n,int m)
{
 int x = cur.x,y = cur.y;
 return (x<=n && x>=1 && y>=1 && y<=m);
}
int minSteps(int n,int m,int sx,int sy,int dx,int dy)
{
    queue<cell> q;
    cell st(sx,sy,0);
    q.push(st);
    
    int vis[n+1][m+1];
    memset(vis,0,sizeof(vis));
    vis[sx][sy] = true;
    pair<int,int>  dir[8] = {{-1,-2},{-2,-1},{-2,1},{-1,2},{1,-2},{2,-1},{2,1},{1,2}};

    while(q.size())
    {
        cell cur = q.front();
        q.pop();
        if(cur.x == dx && cur.y == dy) return cur.dist;
        
        for(int i=0;i<8;i++)
        {
            cell next(cur.x+dir[i].first,cur.y+dir[i].second,cur.dist+1);
            if(issafe(next,n,m) && !vis[cur.x+dir[i].first][cur.y+dir[i].second])
            {
                    vis[cur.x+dir[i].first][cur.y+dir[i].second] = true;
                    q.push(next);
            }
        }
    }
    return -1;
}
int main() {
	int t;cin>>t;while(t--)
	{   
	    int n,m;cin>>n>>m;
	    int sx,sy,dx,dy;
	    cin>>sx>>sy>>dx>>dy;
	   cout<< minSteps(n,m,sx,sy,dx,dy)<<endl;
        
	    
	}
	return 0;
}
