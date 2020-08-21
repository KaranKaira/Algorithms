struct job{
    public:
    int st,end,profit;
};
bool comp (job a,job b)
{
return a.end < b.end;
}
int find(job a[],int i)
{
for(int j=i-1;j>=0;j--)
    if(a[j].end <= a[i].st) return j;
return -1;
    // using binary search
//     int ans = -1;
//     int l = 0,r = i-1;
//     while(l<=r)
//     {
//         int mid = l + (r-l)/2;
//         if(a[mid].end <= a[i].st) {
//             ans = mid;
//             l = mid+1;
//         }
//         else r = mid-1;
//     }
//     return ans;
}
class Solution {
    
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
             int n = startTime.size();
            job a[n];
        for(int i=0;i<n;i++)
        {
            a[i].profit = profit[i];
            a[i].st = startTime[i];
            a[i].end = endTime[i];
        }
        sort(a,a+n,comp);
        int dp[n];
        dp[0] = a[0].profit;
        for(int i=1;i<n;i++)
        {
            
        int ifinclprofit = a[i].profit;
        int latestNonConflict = find(a,i);
        if(latestNonConflict != -1) ifinclprofit += dp[latestNonConflict];
        dp[i] = max(dp[i-1],ifinclprofit);
        }
    
    return dp[n-1];
    }
};
int main()
{
// input output
}
