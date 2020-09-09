class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; ans < nums.size() && ans <= i; ++ans) {
            i = max(ans + nums[ans], i);
            cout << i << " ";
        }
        return ans == nums.size();
    }
};