class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> out;
        for(int i = 0; i < nums.size(); ++i) {
            int pos = abs(nums[i]);
            if(nums[pos-1] > 0)
                nums[pos-1] = nums[pos-1]*(-1);
            else
                out.push_back(pos);
        }
        return out;
    }
};