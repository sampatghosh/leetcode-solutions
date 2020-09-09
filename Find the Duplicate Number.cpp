class Solution {
public:
    int count(vector<int> nums, int x) {
        int out = 0;
        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] <= x)
                ++out;
        return out;
    }
    int findDuplicate(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int l = 1, r = nums.size()-1;
        while(l < r) {
            int mid  = l + (r - l) / 2;
            int c = count(nums,mid);
            if(c > mid)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};