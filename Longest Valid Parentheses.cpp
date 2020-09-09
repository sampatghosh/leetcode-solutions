class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.length(),0);
        int out = 0;
        for(int i = 1; i < s.length(); ++i) {
            if(s[i] == ')') {
                int id = i - dp[i-1] - 1;
                if(id >= 0 and s[id] == '(') {
                    dp[i] = dp[i-1] + 2;
                    if(id > 1)
                        dp[i] += dp[id - 1];
                }
            }
            out = max(out,dp[i]);
        }
        return out;
    }
};