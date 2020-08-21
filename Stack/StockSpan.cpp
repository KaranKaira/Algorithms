#include <iostream>
#include<stack>
using namespace std;
void find(int a[],int n,int ans[])
{
    stack<int> s;
    ans[0] =1 ;
    s.push(0);
    for(int  i=1;i<n;i++)
    {
        while(s.size() && a[s.top()] <= a[i]) s.pop();
        
        ans[i] = (s.empty() ? (i+1) : (i- s.top()));
    s.push(i);
        
    }
    
}
int main() {
	int t;cin>>t;while(t--)
	{
	    int n;cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	   int ans[n];
	    find(a,n,ans);
	    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
