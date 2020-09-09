class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0)
            return {};
        if(nums.size() == 1)
            return {to_string(nums[0])};
        vector<string> out;
        string temp = to_string(nums[0]);
        int id = 0;
        for(int i = 1; i < nums.size(); ++i) {
            if((long)nums[i]-(long)nums[i-1] > 1) {
                if(i-id > 1)
                    temp += "->" + to_string(nums[i-1]);
                out.push_back(temp);
                temp = to_string(nums[i]);
                id = i;
            }
        }
        if((long)nums[nums.size()-1]-(long)nums[nums.size()-2] == 1)
            temp += "->" + to_string(nums[nums.size()-1]);
        out.push_back(temp);
        return out;
    }
};