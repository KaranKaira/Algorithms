#include <bits/stdc++.h>
using namespace std;

int main() {
	//
	int t;cin>>t;while(t--)
	{
	    int n;cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    stack<int> st;
	    int ans = 0;
	    
	    int i = 0 ;
	    while(i<n)
	    {
	        if(st.size() == 0  || a[i] >= a[st.top()] ) st.push(i++);
	        else {
	            int t = st.top();
	            st.pop();
	            
	            ans = max(ans,a[t] * ((st.empty() ? i : i - st.top() - 1)));
	        }
	    }
	    while(st.size())
	    {
	        int t= st.top();
	        st.pop();
	        
	        ans  = max(ans,a[t] * (st.empty()?i:i-st.top()-1));
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
