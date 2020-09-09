class Solution {
public:
    int palLength(string s,int l,int r) {
        while(l >= 0 && r < s.length() && s[l] == s[r]) {
            --l;
            ++r;
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
        ios_base::sync_with_stdio(false);
        if(s == "")
            return "";
        int r = 0, l = 0;
        for(int i = 0; i < s.length(); ++i) {
            int odd = palLength(s,i,i);
            int even = palLength(s,i,i+1);
            int len = max(odd,even);
            if(len > r - l + 1) {
                l = i - ((len - 1) / 2);
                r = l + len - 1;
            }
        }
        string out="";
        for(int i = l; i <= r; ++i)
            out +=s[i];
        return out;
    }
};