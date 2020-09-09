class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        int l = 0, r = nums.size()-1;
        while(l < r) {
            int mid = l + (r-l) / 2;
            if(mid == 0) {
                if(nums[mid] > nums[mid+1])
                    return mid;
                else
                    return mid + 1;
            }
            if(mid == nums.size() - 1) {
                if(nums[mid] < nums[mid+1])
                    return mid;
                else
                    return mid - 1;
            }
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;
            else if(nums[mid - 1] > nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};