class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() > 1) {
            int i = 0, l = 0, r = nums.size()-1;
            while(i <= r) {
                if(nums[i] == 0)
                    swap(nums[l++], nums[i++]);
                else if (nums[i] == 1)
                    ++i;
                else
                    swap(nums[i], nums[r--]);
            }
        }
    }
};