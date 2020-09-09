class Solution {
public:
    int len;
    int minCut(string s, int l, int r, unordered_map<string,int>& dp,  vector<vector<bool>>& palin) {
        if(dp.find(s.substr(l,r-l))!=dp.end() && dp[s]!=len)
            return dp[s.substr(l,r-l)];
        if(r-l==1)
            return 0;
        if(palin[l][r])
            return dp[s] = 0;
        int out = len;
        for(int i = 1; i <= r; ++i) {
            if(palin[l][l+i])
                out = min(out,1+minCut(s,l+i,r-i,dp,palin));
        }
        return dp[s] = out;
    }
    int minCut(string s) {
        len = s.length();
        unordered_map<string,int> dp;
        vector<vector<bool>> palin(s.length(), vector<bool>(s.length(), false));
        for(int j = 0; j < s.length(); ++j) {
            for(int i = j; i >= 0; --i) {
                if(j - i == 0 || s[i] == s[j] && j - i == 1) {
                    palin[i][j] = true;
                } else {
                    palin[i][j] = palin[i+1][j-1] && (s[i] == s[j]);
                }
            }
        }
        return minCut(s,0,s.length()-1,dp,palin);
    }
};