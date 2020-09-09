class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 0 || s[0] == '0')
            return 0;
        vector<int> dp(s.length()+1,1);
        for(int i = 2; i <= s.length(); ++i) {
            if (s[i-1] == '0' && (s[i-2] == '0' || s[i-2] > '2'))
                return 0;
            else if (s[i-2] == '0' && s[i-1] != '0')
                dp[i] = dp[i - 1];
            else if (s[i-2] != '0' &&  s[i-1] == '0')
                dp[i] = dp[i - 2];
            else if (s[i-2]=='1' || (s[i-1] <= '6' && s[i-2] == '2'))
                dp[i]=dp[i-1] + dp[i-2];
            else
                dp[i] = dp[i-1];
        }
        return dp[s.length()];
    }
};