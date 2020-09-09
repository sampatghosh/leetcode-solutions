class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> out;
        if(nums.size()<3)
            return out;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i) {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int l = i+1, r = nums.size()-1;
            while (l<r) {
                int s = nums[i]+nums[l]+nums[r];
                if (s>0)
                    r--;
                else if (s<0)
                    ++l;
                else {
                    out.push_back(vector<int> {nums[i], nums[l], nums[r]});
                    while (l<r && nums[l]==nums[l+1])
                        ++l;
                    while (r>l && nums[r]==nums[r-1])
                        --r;
                    ++l; --r;
                }
            }
        }
        return out;
    }
};