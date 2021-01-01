#include <bits/stdc++.h>
using namespace std;
void mul(int res[],int f,int &sz)
{
    int carry = 0;
    for(int i = 0;i<sz;i++)
    {
        int product = res[i] * f + carry;
        res[i] = product%10;
        carry = product/10;
    }
    while(carry)
    {
        res[sz] = carry%10;
        carry = carry/10;
        sz++;
    }
}
void fac(int n )
{
    int res[10000];
    int sz = 1;
    res[0] = 1;
    for(int i = 2;i<=n;i++)
        mul(res,i,sz);
    for(int i = sz-1;i>=0;i--)
    cout<<res[i];
}
int main() {
	//code
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    fac(n);
	    cout<<endl;
	}
	return 0;
}
