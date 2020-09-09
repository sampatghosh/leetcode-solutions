class Solution {
public:
    vector<string> wbreak(string s,unordered_set<string>& dict, unordered_map<string,vector<string>>& dp) {
        vector<string> out;
        if(dp.find(s)!=dp.end())
            return dp[s];
        if(s.length()==0) {
            out.push_back("");
            return out;
        }
        for(int i = 1; i <= s.length(); ++i) {
            if(dict.find(s.substr(0,i))!=dict.end()) {
                vector<string> res = wbreak(s.substr(i,s.length()-i),dict,dp);
                for(string sub: res) {
                    string space = sub.length()?" ":"";
                    out.push_back(s.substr(0,i)+space+sub);
                }
            }
        }
        dp[s] = out;
        return out;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        unordered_map<string,vector<string>> dp;
        for(auto w : wordDict)
            dict.insert(w);
        return wbreak(s,dict,dp);
    }
};