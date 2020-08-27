//Imagine you have a special keyboard with the following keys: 
//Key 1:  Prints 'A' on screen
//Key 2: (Ctrl-A): Select screen
//Key 3: (Ctrl-C): Copy selection to buffer
//Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed.
//If you can only press the keyboard for N times (with the above four keys), write a program to produce maximum numbers of A's.
//That is to say, the input parameter is N (No. of keys that you can press), the output is M (No. of As that you can produce).

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;cin>>t;while(t--)
	{
	    int n;cin>>n;
	    if(n>75) {
	        cout<<-1<<endl;
	        continue;
	    }
	    int dp[n+1];
	    for(int i=1;i<=6;i++) dp[i] = i;
	    
	    for(int i=7;i<=n;i++)
	    {
	        dp[i] = max({2*dp[i-3],3*dp[i-4],4*dp[i-5]});
	    }
	    cout<<dp[n]<<endl;
	}
	return 0;
}
