class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff = INT_MAX;
        for(int i = 0; i < nums.size()-2; ++i) {
            int l = i + 1, r = nums.size() - 1;
            int t1 = target - nums[i];
            while(l < r) {
                int t = nums[i] + nums[l] + nums[r];
                if(abs(diff) > abs(target-t))
                    diff = target - t;
                if(nums[l]+nums[r] < t1)
                    ++l;
                else if (nums[l]+nums[r] > t1)
                    --r;
                else
                    break;
            }
        }
        return target - diff;
    }
};