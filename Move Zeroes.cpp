class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;
        int p1,p2;
        p1=0;p2=0;
        for(int i=0;i<nums.size();++i) {
            if(nums[i]==0) {
                ++count;
            }
            else {
                nums[p1]=nums[i];
                ++p1;
            }
        }
        for(int i=nums.size()-1; i>=0 && count!=0;--i) {
            nums[i]=0;
            --count;
        }
    }
};