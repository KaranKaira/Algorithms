#include <bits/stdc++.h>
using namespace std;
struct cell{
    int x,y,dist;
    cell(){}
    cell(int x,int y,int dist) : x(x),y(y),dist(dist) {}
};
bool issafe(cell cur,int n,int m)
{
    int i = cur.x,j = cur.y;
    return (i<n && i>=0 && j<m && j>=0) ;
}
int solve( int dx ,int dy,int  n,int m ,vector<vector<int>> &mat,vector<vector<int>> &used)
{
   
   cell init = cell(0,0,0);
   queue<cell> q ;
   q.push(init);
   int dirx[4] = {-1,0,1,0},diry[4] = {0,-1,0,1};
   while(q.size())
   {
       int ok = 0;
       int c = q.size();
       while(c--)
       {
           cell now = q.front();
           q.pop();
           used[now.x][now.y] = 1;
           if(now.x == dx && now.y == dy) return now.dist;
           
           for(int i=0;i<4;i++)
           {
               cell next = cell(now.x+dirx[i],now.y+diry[i],now.dist+1);
               
               if(issafe(next,n,m) && used[next.x][next.y]==0 && mat[next.x][next.y] ==1 )
               {
                   q.push(next);
                   ok= true;
               }
           }
           
       }
       if(ok == false) return -1;
   }
}
int main() {
	int t;cin>>t;while(t--)
	{
	    int n,m;cin>>n>>m;
	    vector<vector<int>> mat(n,vector<int>(m)),used(n,vector<int>(m,0));

	    for(int i=0;i<n;i++)
	    for(int j =0;j<m;j++) cin>>mat[i][j];
	    int x,y;cin>>x>>y;
	    
	    if(mat[0][0]==0 || mat[x][y]==0) {
	        cout<<-1<<endl;
	        continue;
	    }
        if(x == 0 && y == 0) {
            cout<<0<<endl;
            continue;
        }
	  
	  //BFS
	  cout<< solve(x,y,n,m,mat,used) << endl;

    return 0;
}
