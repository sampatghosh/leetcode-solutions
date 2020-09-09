class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.length()==0)
            return 0;
        int counter[26] = {0};
        for (int i = 0; i < s.length(); ++i)
            ++counter[s[i]-'a'];
        for(int i = 0; i < s.length(); ++i) {
            if(counter[s[i]-'a'] < k) {
                int left = longestSubstring(s.substr(0,i),k);
                int right = longestSubstring(s.substr(i+1),k);
                return max(left,right);
            }
        }
        return s.length();
    }
};