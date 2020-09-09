class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() == 0 || t.size() == 0)
            return "";
        vector<int> v(128, 0);
        for(auto c:t)
            ++v[c];
        int start=0, end=0, count=t.size(), minLow=0, minRight=INT_MAX, l =s.size();
        while(end<l ){
            if(v[s[end]] > 0)
                --count;
            --v[s[end]];
            ++end;
            while(count==0) {
                if(end-start<minRight) {
                    minLow=start;
                    minRight=end-start;
                }
                ++v[s[start]];
                if(v[s[start]] > 0)
                    ++count;
                ++start;
            }
        }
        return minRight == INT_MAX? "" : s.substr(minLow, minRight);
    }
};