class Solution {
public:
    bool isMatch(string s, string p) {
        ios_base::sync_with_stdio(false);
        int n = s.length(), m = p.length();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;
        for(int i=1;i<=m;++i) {
            if(p[i-1]=='*')
                dp[i][0]= true && dp[i-1][0];
        }
        for(int i = 1; i <= m; ++i) {
            for(int j = 1;j <= n; ++j) {
                if(p[i-1]=='*')
                    dp[i][j] = (dp[i-1][j-1] || dp[i][j-1] || dp[i-1][j]);
                else if(s[j-1]==p[i-1] || p[i-1]=='?')
                    dp[i][j] = dp[i-1][j-1];
            }
        }
        return dp[m][n];
    }
};