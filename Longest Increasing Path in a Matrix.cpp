class Solution {
public:
    int DFS(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(dp[i][j] != -1)
            return dp[i][j];
        int length = 1;
        int up = 1, down = 1, left = 1, right = 1;
        if(j + 1 < matrix[0].size() and matrix[i][j] < matrix[i][j+1])
            right += DFS(i,j+1,matrix,dp);
        if(j > 0 and matrix[i][j] < matrix[i][j-1])
            left += DFS(i,j-1,matrix,dp);
        if(i + 1 < matrix.size() and matrix[i][j] < matrix[i+1][j])
            down += DFS(i+1,j,matrix,dp);
        if(i > 0 and matrix[i][j] < matrix[i-1][j])
            up += DFS(i-1,j,matrix,dp);
        return dp[i][j] = max(right,max(left,max(up,down)));
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 or matrix[0].size() == 0)
            return 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(),-1));
        int ans = 0;
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j)
                ans = max(ans,DFS(i,j,matrix,dp));
        }
        return ans;
    }
};