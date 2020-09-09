class Solution {
public:
    bool check(int req[]) {
        for(int i = 0; i < 26; ++i)
            if(req[i] != 0)
                return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> out;
        int len1 = s.length();
        int len2 = p.length();
        if(len1 < len2)
            return out;
        int req[26] = {0};
        for(int i = 0; i < len2; ++i) {
            req[p[i]-'a'] ++;
        }
        for(int i = 0; i < len2; ++i) {
            req[s[i]-'a']--;
        }
        if(check(req))
            out.push_back(0);
        for(int i = len2; i < len1; ++i) {
            req[s[i]-'a']--;
            req[s[i-len2]-'a']++;
            if(check(req))
                out.push_back(i-len2+1);
        }
        return out;
    }
};