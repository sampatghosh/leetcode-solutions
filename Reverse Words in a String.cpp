class Solution {
public:
    string reverseWords(string s) {
        int i, l = 0, r = s.length()-1;
        for(i = 0; i < s.length() and s[i] == ' '; ++i);
        l = i;
        for(i = s.length()-1; i >= 0 and s[i] == ' '; --i);
        r = i;
        int len = 0;
        for (i = l; i <= r; ++i) {
            if (s[i] != ' ' || s[i - 1] != ' ')
                s[len++] = s[i];
        }
        s.erase(s.begin() + len, s.end());
        reverse(s.begin(),s.end());
        l = 0;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i]==' ') {
                reverse(s.begin()+l,s.begin()+i);
                l = i+1;
            }
        }
        reverse(s.begin()+l,s.end());
        return s;
    }
};