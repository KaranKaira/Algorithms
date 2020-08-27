// Using Branch And Bound


#include <bits/stdc++.h>
using namespace std;
bool ok;
set<vector<int>> ans;
void makeSolution(vector<vector<int>>&mat)
{
    int n = mat.size();
    vector<int> now;
    for(int col=0;col<n;col++)
    {
        for(int row=0;row<n;row++)
        {
            if(mat[row][col])
            {
                now.push_back(row+1);
                break;
            }
        }
    }
    ans.insert(now);
    
}
void solve(vector<vector<int>>&mat,vector<bool> &col,vector<bool>&ldiag,vector<bool>&rdiag,int row)
{
    if(row == (int)mat.size())
    {
     makeSolution(mat);
     ok = true;
     return;
    }
    int n = mat.size();
   for(int i=0;i<n;i++)
   {
       if(col[i] == false && ldiag[row-i+n-1]==false && rdiag[row+i]==false)
       {
           col[i] = ldiag[row-i+n-1] = rdiag[row+i]  =true;
           mat[row][i] = 1;
           solve(mat,col,ldiag,rdiag,row+1);
           mat[row][i] = 0;
           col[i] = ldiag[row-i+n-1] = rdiag[row+i]  =false;
           
       }
   }
    
    
    
}
int main() {
	int t;cin>>t;while(t--)
	{
	    int n;cin>>n;
	    vector<vector<int>> mat(n,vector<int>(n,0));
	    ok = false;
	    ans.clear();
	    vector<bool> col(n,0),ldiag(2*n-1,0),rdiag(2*n-1,0);
	   // vector<int> ans(n,0);
	    solve(mat,col,ldiag,rdiag,0);
	    if(ok == false) {cout<<-1<<endl;
	    continue;
	}
	
	for(auto it=ans.begin();it!=ans.end();it++)
	{
	    vector<int> now  = *it;
	    cout<<"[";
	    for(int j :now) cout<<j<<" ";
	    cout<<"] ";
	    
	}
	cout<<endl;
	     
	        
	 }
	   
	    
	
	return 0;
}
