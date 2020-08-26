#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;cin>>t;while(t--)
	{
	int n,k;cin>>n>>k;
	int a[n];
	deque<int> q(k);
	
	for(int i=0;i<n;i++) cin>>a[i];
    int i;
    for(i=0;i<k;i++)
    {
        while(q.size() && a[q.back()]<=a[i] )  q.pop_back();
        q.push_back(i);
    }
    for(;i<n;i++)
    {
        cout<<a[q.front()]<<" ";
        while(q.size() && q.front() <= i-k) q.pop_front();
        while(q.size() && a[q.back()]<=a[i]) q.pop_back();
        q.push_back(i);
    }
        cout<<a[q.front()];
	cout<<endl;
	}
	return 0;
}
