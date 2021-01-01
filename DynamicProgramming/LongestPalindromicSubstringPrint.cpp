class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<n;i++) dp[i][i]=1;
        for(int i= 0;i<n-1;i++)
            if(s[i]==s[i+1]) dp[i][i+1] = 1;
        for(int len = 3;len<=n;len++)
            for(int i = 0 , j = i + len - 1 ;j < n ;j++,i++)
            {
                dp[i][j] = s[i] == s[j] && dp[i+1][j-1];
            }
        string ans = "";
        for(int len = n ;len;len--)
        {
            for(int i = 0 ; i + len-1 < n;i++)
                if(dp[i][i+len-1]) return s.substr(i,len);
        }
        return s.substr(0,1);
    }
};
