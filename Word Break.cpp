class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<vector<bool>> dp(s.length(),vector<bool>(s.length(),false));
        unordered_set<string> dict;
        for(auto w : wordDict)
            dict.insert(w);
        for(int l = 1; l <= s.length(); ++l) {
            for(int i = 0; i < s.length()-l+1; ++i) {
                int j = i + l - 1;
                if(dict.find(s.substr(i,l))!=dict.end())
                    dp[i][j] = true;
                else {
                    for(int k = i; k <= j; ++k) {
                        if(dp[i][k] && dp[k+1][j]) {
                            dp[i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][s.length()-1];
    }
};