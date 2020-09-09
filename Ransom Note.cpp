class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.length()==0)
            return true;
        if(magazine.length()==0)
            return false;
        unordered_map<char,int> mp;
        for(char c:magazine) {
            if(mp.find(c)==mp.end())
                mp[c]=1;
            else
                ++mp[c];
        }
        for(int i = 0;i<ransomNote.length();++i) {
            if(mp.find(ransomNote[i])!=mp.end()) {
                if(mp[ransomNote[i]]==0)
                    return false;
                else
                    --mp[ransomNote[i]];
            }
            else
                return false;
        }
        return true;
    }
};