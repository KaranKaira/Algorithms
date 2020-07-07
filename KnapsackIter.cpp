#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(v) v.begin(),v.end()
#define mod 1000000007 ;
typedef long long ll;



ll in[200000][2];  // 0th colummn is weight of item and 1st column is profit
int n,W;
void solve()
{		
		cin>>n>>W;
		for(int i = 1;i<=n;i++)
			cin>>in[i][0]>>in[i][1];  
     int K[n + 1][W + 1]; 
  
    // Build table K[][] in bottom up manner 
    for (i = 0; i <= n; i++) { 
        for (w = 0; w <= W; w++) { 
            if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (wt[i - 1] <= w) 
                K[i][w] = max( 
                    val[i - 1] + K[i - 1][w - wt[i - 1]], 
                    K[i - 1][w]); 
            else
                K[i][w] = K[i - 1][w]; 
        } 
    } 
  
    cout<< K[n][W]; 
		
}
int main()
{
	solve();
  return 0;
}
