#include <bits/stdc++.h>
using namespace std;
int FindPeak(int a[],int n)
{
    int l=0,r=n-1;
    while(l<=r)
    {
        int mid = l+(r-l)/2;
        if((mid==l || a[mid-1] < a[mid]) && (mid==r || a[mid+1] < a[mid])) return mid;
        else if(a[mid+1] > a[mid]) l = mid+1;
        else r = mid-1;
    }
    return -1;
}
int bs(int a[],int l,int r,int x,bool isincre)
{
    while(l<=r)
    {
        int mid = l+(r-l)/2;
        if(a[mid]==x) return mid;
        else if(a[mid] < x) {
            if(isincre) l = mid+1;
            else r = mid-1;
        }
        else {
            if(isincre) r = mid-1;
            else l = mid+1;
    }
    }
    return -1;
    
}
int main()
{
	//code
	int t;cin>>t;while(t--)
	{
	    int n;cin>>n;int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    int x;cin>>x;
	    int peakInd = FindPeak(a,n);
	    if(a[peakInd] == x) {cout<<peakInd<<endl; continue;}
	    int in1 = bs(a,0,peakInd-1,x,true);
	    if(in1!=-1) {cout<<in1<<endl;continue;}
	    in1 = bs(a,peakInd+1,n-1,x,false) ;
	    if(in1!=-1) {cout<<in1<<endl;continue;}
	    cout<<-1<<endl;
	}
	return 0;
}
