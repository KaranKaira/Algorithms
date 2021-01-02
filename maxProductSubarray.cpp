class Solution {
public:
    int maxProduct(vector<int>& a) {
        
       int ans = a[0] , max_here = a[0] , min_here = a[0];
       for(int i =1;i<a.size();i++)
       {
        int t = max_here;
           max_here = max({max_here*a[i],a[i],min_here*a[i]});
           min_here = min({a[i] , t * a[i] , min_here * a[i]});
           ans = max(ans , max_here);
       }
        return ans;
    }
};
