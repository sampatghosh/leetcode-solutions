class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> out;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < (int)nums.size()-2; ++i) {
            if (i && nums[i] == nums[i-1])
                continue;
            for(int j = i + 1; j < (int)nums.size()-1; ++j) {
                if (j != i+1 && nums[j] == nums[j-1])
                    continue;
                int l = j + 1, r = (int)nums.size() - 1;
                while(l < r) {
                    int s = nums[i] + nums[j] + nums[l] + nums[r];
                    if(s == target) {
                        out.push_back({nums[i],nums[j],nums[l],nums[r]});
                        while (l < r && nums[l] == nums[l+1])
                            ++l;
                        while (l < r && nums[r] == nums[r-1])
                            --r;
                        ++l;
                        --r;
                    } else if(s < target)
                        ++l;
                    else
                        --r;

                }
            }
        }
        return out;
    }
};