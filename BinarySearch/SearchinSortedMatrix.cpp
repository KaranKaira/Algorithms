#include <iostream>
using namespace std;

int main()
{
	//code
	int t;cin>>t;while(t--)
	{
	    int n,m;cin>>n>>m;
	    int a[n][m];
	    for(int i=0;i<n;i++)
	    for(int j=0;j<m;j++) cin>>a[i][j];
	    int x ;cin>>x;
	    int i = 0,j = m-1;
	    while(i>=0&&i<n && j>=0 && j<m)
	    {
	        if(a[i][j] == x) {
	            cout<<1<<endl;
	            goto finish;
	        }
	        else if(a[i][j] > x){
	            j--;
	        }
	        else{
	            i++;
	        }
	    }
	    cout<<0<<endl;
	    finish:;
	}
	return 0;
}
