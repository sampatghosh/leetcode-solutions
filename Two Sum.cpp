class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> s;
        vector<int> out;
        for(int i=0;i<nums.size();++i) {
            unordered_map<int,int>::const_iterator got = s.find (target-nums[i]);
            if(got!=s.end()) {
                out.push_back(got->second);
                out.push_back(i);
                break;
            }
            else
                s.insert(make_pair(nums[i],i));
        }
        return out;
    }
};