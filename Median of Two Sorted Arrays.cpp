class Solution {
public:
    double median(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int l = 0, r = n;
        double ans = 0;
        while(l <= r) {
            int X = l + ((r-l) / 2);
            int Y = (n + m + 1) / 2 - X;
            int leftX = (X == 0) ? INT_MIN : nums1[X - 1];
            int rightX = (X == n) ? INT_MAX : nums1[X];
            int leftY = (Y == 0) ? INT_MIN : nums2[Y - 1];
            int rightY = (Y == m) ? INT_MAX : nums2[Y];
            if (leftX <= rightY && leftY <= rightX) {
                if ((n + m) % 2)
                    ans = max(leftX, leftY);
                else
                    ans = (max(leftX,leftY) + min(rightX,rightY)) / 2.0;
                break;
            } else if (leftX > rightY)
                r = X - 1;
            else
                l = X + 1;
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        if(nums1.size()<nums2.size())
            return median(nums1,nums2);
        else
            return median(nums2,nums1);
    }
};