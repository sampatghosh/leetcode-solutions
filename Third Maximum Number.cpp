class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size()<3) {
            if(nums.size()==2)
                return (nums[0]>nums[1])?nums[0]:nums[1];
            else
                return nums[0];
        }
        long long int l1,l2,l3;
        l1=l2=l3=-9223372036854775807;
        for(int i=0;i<nums.size();++i) {
            if(l1<nums[i]) {
                l3=l2;
                l2=l1;
                l1=nums[i];
            }
            else if(l2<nums[i] && nums[i]!=l1) {
                l3=l2;
                l2=nums[i];
            }
            else if(l3<nums[i] && nums[i]!=l2 && nums[i]!=l1)
                l3=nums[i];
        }
        if(l3!=-9223372036854775807)
            return l3;
        else
            return l1;
    }
};