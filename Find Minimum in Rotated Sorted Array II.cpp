class Solution {
public:
    int check(vector<int>& a,int l, int r) {
        if(l<r) {
            if(a[l]==a[r])
                return check(a,l,r-1);
            if(r-l==1)
                return a[l]<a[r]?a[l]:a[r];
            int mid = (l + r) / 2;
            if(a[mid]<=a[r])
                return check(a,l,mid);
            else
                return check(a,mid,r);
        }
        return a[r];
    }
    int findMin(vector<int>& nums) {
        return check(nums,0,nums.size()-1);
    }
};