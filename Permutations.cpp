class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int p = 1;
        for(int i = 1; i <= nums.size(); ++i)
            p*=i;
        vector<vector<int>> out;
        out.push_back(nums);
        for(int i = 2; i <= p; ++i) {
            next_permutation(nums.begin(),nums.end());
            out.push_back(nums);
        }
        return out;
    }
};