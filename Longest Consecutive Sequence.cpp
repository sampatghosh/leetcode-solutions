class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        unordered_set<int> st;
        for(int i : nums)
            st.insert(i);
        int out = 0;
        for(int i : nums) {
            st.erase(i);
            int curr = i;
            int len = 1;
            while(st.find(curr-1)!=st.end()) {
                st.erase(curr-1);
                curr--;
                ++len;
            }
            curr = i;
            while(st.find(curr+1)!=st.end()) {
                st.erase(curr+1);
                curr++;
                ++len;
            }
            out = max(len,out);
        }
        return out;
    }
};