class Solution {
public:
    int check(vector<int>& a,int l, int r) {
        if(l<r) {
            if(r-l==1)
                return a[l]<a[r]?a[l]:a[r];
            int mid = (l + r) / 2;
            if(a[mid]<a[r])
                return check(a,l,mid);
            else
                return check(a,mid,r);
        }
        return a[r];
    }
    int findMin(vector<int>& nums) {
        if(nums[0]<nums[nums.size()-1])
            return nums[0];
        else
            return check(nums,0,nums.size()-1);
    }
};