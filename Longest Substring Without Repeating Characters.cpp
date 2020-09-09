class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ios_base::sync_with_stdio(false);
        int l=0,i=0;
        int loc[256];
        memset(loc,-1, sizeof(loc));
        int max=0;
        for(i = 0; i < s.length(); ++i) {
            if(loc[s[i]]==-1) {
                loc[s[i]]=i;
            }
            else {
                if(loc[s[i]]>=l) {
                    int temp = loc[s[i]]+1;
                    if(i-l>max)
                        max = i-l;
                    while(l<temp)
                        loc[s[l++]]=-1;
                    loc[s[i]] = i;

                }
            }
        }
        return i-l>max?i-l:max;
    }
};