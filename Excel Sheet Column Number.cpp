class Solution {
public:
    int titleToNumber(string s) {
        int out = 0;
        for(int i = 0; i < s.length(); ++i) {
            out = out*26 + (s[i]-65+1);
        }
        return out;
    }
};