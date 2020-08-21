#include <iostream>
#include<stack>
using namespace std;

int main() {
	//code
	int t;cin>>t;while(t--)
	{
	    int n;cin>>n;
	    long long  a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    stack<long long> s;
	    long long ans[n];
	    ans[n-1] = -1;
	    s.push(a[n-1]);
	    for(int i=n-2;i>=0;i--)
	    {
	        while(s.size() && s.top() < a[i]) s.pop();
	        ans[i] = (s.empty() ? -1 : s.top());
	        s.push(a[i]);
	    }
	    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
