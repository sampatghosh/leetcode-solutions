class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0)
            return 0;
        int dp[matrix.size()+1][matrix[0].size()+1];
        int max = 0;

        for(int i = 0; i <= matrix.size(); ++i)
            dp[i][0] = 0;

        for(int i = 1; i <= matrix[0].size(); ++i)
            dp[0][i] = 0;

        for(int i = 1; i <= matrix.size(); ++i) {

            for(int j = 1; j <= matrix[0].size(); ++j) {

                if(matrix[i-1][j-1] == '1') {
                    dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]));

                    if(dp[i][j] > max)
                        max = dp[i][j];

                }
                else
                    dp[i][j] = 0;
            }
        }
        return max*max;
    }
};