#include <iostream>
using namespace std;
bool isvalid(long long  a[],int n,long long  mid,int m)
{
    int stu = 1;
    long long sum =0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];

        if(sum > mid)
        {
            stu++;sum = a[i];
        }
        if(stu>m) return false;                
        
    }
    return true;
}
int main() {
	
	int t;cin>>t;while(t--)
	{
	    int n;cin>>n;long long a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    int m;cin>>m;
	    if(n<m) {
	        cout<<-1<<endl;
	        continue;
	    }
	    long long  ma = a[0];
	    long long sum  = 0;
	    for(int i=0;i<n;i++) {
	        sum+=a[i];
	        if(ma<a[i]) ma = a[i];
	    }
	    long long  st = ma,end=sum;
	    long long  res;
	    while(st<=end)
	    {
	        long long  mid = st + (end-st)/2;
	        if(isvalid(a,n,mid,m)) {
	            res = mid;
	            end = mid-1;
	        }
	        else st = mid+1;
	    }
	    cout<<res<<endl;
	}
	return 0;
}
