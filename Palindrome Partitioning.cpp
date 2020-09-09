class Solution {
public:
    bool isPal(string s) {
        for(int i = 0; i < s.length()/2; ++i)
            if(s[i]!=s[s.length()-1-i])
                return false;
        return true;
    }
    vector<vector<string>> partition(string s,
                                     unordered_map<string,vector<vector<string>>>& dp) {
        if(dp.find(s)!=dp.end())
            return dp[s];
        vector<vector<string>> out;
        if(s.length()==0) {
            out.push_back({});
            return out;
        }
        for(int i = 1; i <= s.length(); ++i) {
            bool ans = isPal(s.substr(0,i));
            if(ans) {
                vector<vector<string>> res = partition(s.substr(i,s.length()-i),dp);
                for(vector<string> sub : res) {
                    vector<string> temp;
                    temp.push_back(s.substr(0,i));
                    if(sub.size()>0)
                        temp.insert(temp.end(),sub.begin(),sub.end());
                    out.push_back(temp);
                }
            }
        }
        dp[s] = out;
        return out;
    }
    vector<vector<string>> partition(string s) {
        unordered_map<string,vector<vector<string>>> dp;
        return partition(s,dp);
    }
};