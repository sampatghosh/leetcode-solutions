class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l[nums.size()],r[nums.size()];
        l[0]=nums[0];
        for(int i=1;i<nums.size();++i) {
            l[i]=l[i-1]*nums[i];
        }
        r[nums.size()-1] = nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;--i) {
            r[i]=r[i+1]*nums[i];
        }
        vector<int> out;
        out.push_back(r[1]);
        for(int i=1;i<nums.size()-1;++i) {
            out.push_back(l[i-1]*r[i+1]);
        }
        out.push_back(l[nums.size()-2]);
        return out;
    }
};