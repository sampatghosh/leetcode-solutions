// https://www.youtube.com/watch?v=Pw6lrYANjz4
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
            return 0;
        int n = prices.size();
        vector<vector<int>> dp(2,vector<int>(n,0));
        int k = 2;
        for(int i = 1; i <= k; ++i) {
            int curr = i % 2;
            int maxi = INT_MIN;
            for(int j = 1; j < n; ++j) {
                int prev = (curr + 1) % 2;
                maxi = max(maxi,dp[prev][j-1]-prices[j-1]);
                dp[curr][j] = max(prices[j]+maxi,dp[curr][j-1]);
            }
        }
        return dp[k%2][n-1];
    }
};