class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> out(2,-1);
        if(nums.size() == 0)
            return out;
        out[0] = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        if(out[0] == nums.size() or nums[out[0]] != target) {
            out[0] = -1;
            return out;
        }
        out[1] = upper_bound(nums.begin()+out[0],nums.end(),target) - nums.begin() - 1;
        return out;
    }
};