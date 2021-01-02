//n/3
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
     int cand1 , cnt1=0 , cand2 , cnt2=0;
        int reqd = nums.size()/3;
        for(int i : nums)
        {
            if(cand1 == i ) cnt1++;
            else if(cand2 == i) cnt2++;
            else if(cnt1 == 0 ) {
                cand1 = i ; 
                cnt1++;
            }
            else if(cnt2 == 0 )
            {
                cand2 = i ; 
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        cnt1 =  cnt2 = 0;
        for(int i : nums)
            if(i == cand1) cnt1++;
            else if(i == cand2 ) cnt2++;
        if(cnt1>reqd) ans.push_back(cand1);
        if(cnt2>reqd) ans.push_back(cand2);
        return ans;
    }
};
