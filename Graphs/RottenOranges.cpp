#include <bits/stdc++.h>
using namespace std;
int mat[101][101];
queue<pair<int,int>> q;
bool checkall(int  n,int m)
{
    for(int i  =0 ;i<n;i++)
    for(int j =0;j<m;j++) if(mat[i][j]==1) return true;
    return false;
}
bool issafe(int x,int y,int n,int m)
{
    return (x>=0 && x<n && y>=0 && y<m);
}
int main() {
	//code
	int t;cin>>t;while(t--)
	{
	    int n,m;cin>>n>>m;
	    
	    memset(mat,-1,sizeof(mat));
	    queue<pair<int,int>> t;
	    q = t;
	    for(int i= 0;i<n;i++)
	    for(int j = 0;j<m;j++) {
	        cin>>mat[i][j];
	        if(mat[i][j] == 2) q.push({i,j});
	    }
	    int diri[4] = {-1,0,1,0},dirj[4] = {0,-1,0,1};
	    int ans = 0;
	    bool ok = false;
	    while(q.size())
	    {
	       int c = q.size();
	       ok = false;
	       while(c--)
	       {
	           pair<int,int> x = q.front();
	           q.pop();
	           
	        for(int i=0;i<4;i++)
	        {
	            int nextx = x.first+diri[i],nexty =  x.second + dirj[i];
	            if(issafe(nextx,nexty,n,m) && mat[nextx][nexty]==1)
	            {
	                ok  = true;
	                mat[nextx][nexty] = 2;
	                q.push({nextx,nexty});
	                
	            }
	            
	        }
	           
	           
	       }
	       if(ok) ans++;
	       else break;
	       
	    }
	   cout<<(checkall(n,m)?-1:ans)<<endl;
	}
	return 0;
}
