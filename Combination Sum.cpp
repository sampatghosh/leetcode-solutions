class Solution {
public:
    vector<vector<int>> solve(vector<int>& candidates, vector<vector<vector<int>>>& dp, int target, int index) {
        vector<vector<int>> out;
        if(target <= 0)
            return out;
        if(dp[target].size()>0)
            return dp[target];
        for(int i = index; i < candidates.size() && candidates[i] <= target; ++i) {
            if(candidates[i] == target) {
                out.push_back({candidates[i]});
            } else {
                vector<vector<int>> res = solve(candidates, dp, target-candidates[i],i);
                for(int j = 0; j < res.size(); ++j) {
                    vector<int> temp;
                    temp.push_back(candidates[i]);
                    temp.insert(temp.end(),res[j].begin(),res[j].end());
                    out.push_back(temp);
                }
            }
        }
        dp[target] = out;
        return out;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target+1);
        dp[0].push_back(vector<int>());
        sort(candidates.begin(),candidates.end());
        return solve(candidates, dp, target, 0);
    }
};