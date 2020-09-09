class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int s) {
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i)
            sum += nums[i];
        if(sum < s or (sum + s) % 2)
            return 0;
        int s1 = (sum + s) / 2;
        vector<vector<int>> dp(nums.size()+1,vector<int>(s1+1,0));
        dp[0][0] = 1;
        for(int i = 1; i <= nums.size(); ++i) {
            if(nums[i-1] == 0)
                dp[i][0] = 2*dp[i-1][0];
            else
                dp[i][0] = dp[i-1][0];
        }
        for(int i = 1; i <= nums.size(); ++i) {
            for(int j = 1; j <= s1; ++j) {
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[nums.size()][s1];
    }
};