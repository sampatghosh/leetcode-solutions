class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0], vote=1;
        for(int i = 0; i < nums.size(); ++i) {
            if( nums[i] == majority )
                vote++;
            else if( --vote == 0 ) {
                majority = nums[i];
                vote = 1;
            }
        }
        return  majority;
    }
};