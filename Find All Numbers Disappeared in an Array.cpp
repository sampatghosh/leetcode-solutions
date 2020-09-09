class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] > 0) {
                if(nums[nums[i]-1] > 0)
                    nums[nums[i]-1] *= (-1);
            } else {
                if(nums[((-1)*nums[i])-1] > 0)
                    nums[((-1)*nums[i])-1] *= (-1);
            }
        }
        vector<int> out;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] > 0)
                out.push_back(i+1);
        }
        return out;
    }
};