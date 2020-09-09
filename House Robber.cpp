class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        vector<int> dp(nums.size()+1);
        dp[0] = nums[0];
        int out = dp[0];
        for(int i = 1; i < nums.size(); ++i) {
            dp[i] = nums[i];
            for(int j = i - 2; j >= 0; --j)
                dp[i] = max(dp[i],nums[i] + dp[j]);
            out = max(out,dp[i]);
        }
        return out;
    }
};