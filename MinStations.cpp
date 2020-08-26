#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;cin>>t;while(t--)
	{
	    
	int n;cin>>n;
	int a[n],d[n];
	for(int i=0;i<n;i++) {
	    cin>>a[i];
	}
	for(int i=0;i<n;i++) {
        cin>>d[i];
	}

    int ans = 1,i=1,j=0,cur=1;
    sort(a,a+n);
    sort(d,d+n);
    while(i<n && j < n)
    {
        if(a[i] <= d[j])
        {
            cur++;
            i++;
        }
        else if(a[i] > d[j]){
            j++;cur--;
        }
        ans = max(ans,cur);
    }

    cout<<ans<<endl;
	}
	
	return 0;
}
