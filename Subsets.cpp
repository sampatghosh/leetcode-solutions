class Solution {
public:
    vector<vector<int>> out;
    vector<int> vec;
    void backtrack(int i, vector<int>& nums) {
        out.push_back(vec);
        for(int j = i; j < nums.size(); ++j) {
            vec.push_back(nums[j]);
            backtrack(j+1,nums);
            vec.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0,nums);
        return out;
    }
};