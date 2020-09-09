class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastID(26,-1);
        vector<bool> inOut(26,false);
        for(int i = 0; i < s.length(); ++i)
            lastID[s[i]-'a'] = i;
        string out;
        for(int i = 0; i < s.length();++i) {
            if(inOut[s[i]-'a'])
                continue;
            else if(out.length()==0) {
                out.push_back(s[i]);
                inOut[s[i]-'a'] = true;
            }
            else {
                while(!out.empty() && out.back() > s[i] && lastID[out.back()-'a'] >= i) {
                    inOut[out.back()-'a'] = false;
                    out.pop_back();
                }
                out.push_back(s[i]);
                inOut[s[i]-'a'] = true;
            }
        }
        return out;
    }
};