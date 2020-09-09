class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size()==0)
            return {};
        vector<int> out(2,0);
        int temp = nums[0];
        for(int i = 1; i < nums.size(); ++i)
            temp ^= nums[i];
        int setBit = temp&(temp-1) ^ temp;
        for(int i = 0; i < nums.size(); ++i) {
            if(setBit & nums[i])
                out[0] ^= nums[i];
            else
                out[1] ^= nums[i];
        }
        return out;
    }
};