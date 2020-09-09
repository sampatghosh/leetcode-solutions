class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> out;
        map<string,vector<string>> mp;
        map<string,vector<string>>::iterator it;
        for(int i=0;i<strs.size();++i) {
            string str = strs[i];
            sort(str.begin(), str.end());
            mp[str].push_back(strs[i]);
        }
        for (auto it : mp) {
            out.push_back(it.second);
        }
        return out;
    }
};