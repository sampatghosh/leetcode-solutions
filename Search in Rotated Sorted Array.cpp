class Solution {
public:
    int find(int x,vector<int>& arr,int l, int r) {
        if (l <= r) {
            int mid = l + (r - l)/2;
            if (arr[mid] == x)
                return mid;
            if (arr[mid] > x)
                return find(x,arr, l, mid-1);
            return find(x,arr, mid+1, r);
        }
        else
            return -1;
    }
    int check(vector<int>& a,int l, int r) {
        if(l<r) {
            if(r-l==1)
                return a[l]<a[r]?l:r;
            int mid = (l + r) / 2;
            if(a[mid]<a[r])
                return check(a,l,mid);
            else
                return check(a,mid,r);
        }
        return r;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)
            return -1;
        int piv = check(nums,0,nums.size()-1);
        int l = find(target,nums,0,piv-1);
        int r = find(target,nums,piv,nums.size()-1);
        if(l==-1) {
            if(r==-1)
                return -1;
            else
                return r;
        }
        else
            return l;
    }
};