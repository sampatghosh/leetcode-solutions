class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> dp;
        for(int i : nums) {
            int pos = lower_bound(dp.begin(),dp.end(),i) - dp.begin();
            if(pos < dp.size())
                dp[pos] = i;
            else
                dp.push_back(i);
            if(dp.size()==3)
                return true;
        }
        return false;
    }
};