class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minSum = nums.size() + 1;
        int l = 0, sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(sum < s)
                sum += nums[i];
            while(sum >= s) {
                minSum = min(minSum,i-l+1);
                sum -= nums[l++];
            }
        }
        return minSum == nums.size() + 1 ? 0 : minSum;
    }
};