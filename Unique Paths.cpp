/*
 * DP(m,n) = 1; if m = 1 or n = 0
 *           DP(m-1,n) + DP(m,n-1); otherwise
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0)
            return 0;
        vector<vector<int>> dp(m,vector<int>(n,1));
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
        return dp[m-1][n-1];
    }
};