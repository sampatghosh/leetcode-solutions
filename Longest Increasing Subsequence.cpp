/*  DP approach O(n^2):-
 *  F(k) = 1 ; k = 0
 *         1 + max(F(k-x) iff nums[k] > nums[x] and 0 <= x < k)
 *
 *  Optimized DP approach O(nlogn):-
 *   for every index we are finding the longeset increasing subsequence ending at that index.
 *      1. if the current element is greater than the previous element we push it in the vector
 *      2. if the current element is less than the previous element we find the lower bound of the element in the answer vector and replace the element with the current index value as we can find the longest subsequence in increasing order if we take the minimum values of the array, that is if we take the minimum values now we can maximise the length of our answer.
 *
 *
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        if(nums.size()==0)
            return 0;
        // int n = nums.size();
        // vector<int>dp(n,1);
        // int out = 1;
        // for(int i = 1; i < n; ++i) {
        //     int top = 0;
        //     for (int j = 0; j < i; ++j)
        //         if(nums[j]<nums[i])
        //             top = max(top,dp[j]);
        //     dp[i] = top + 1;
        //     out = max(out,dp[i]);
        // }
        // return out;
        vector<int> dp;
        int n=nums.size();
        for(auto it:nums) {
            int pos = lower_bound(dp.begin() , dp.end() , it) - dp.begin();
            if(pos < dp.size())
                dp[pos] = it;
            else
                dp.push_back(it);
        }
        return dp.size();
    }
};