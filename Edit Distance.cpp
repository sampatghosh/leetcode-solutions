class Solution {
public:
    int minDistance(string word1, string word2) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int m = word1.length()+1;
        int n = word2.length()+1;
        int dp[m][n];
        for(int i = 0; i < m; ++i)
            dp[i][0] = i;
        for(int i = 0; i < n; ++i)
            dp[0][i] = i;
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
            }
        }
        return dp[m-1][n-1];
    }
};