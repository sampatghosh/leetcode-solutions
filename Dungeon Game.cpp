class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 1;
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> dp(r+1,vector<int>(c+1, INT_MAX));
        dp[r][c-1] = 1;
        dp[r-1][c] = 1;
        for(int i = r - 1; i >= 0; --i) {
            for(int j = c - 1; j >= 0; --j) {
                dp[i][j] = min(dp[i+1][j],dp[i][j+1]) - grid[i][j];
                if(dp[i][j] <= 0)
                    dp[i][j] = 1;
            }
        }
        return dp[0][0];

    }
};