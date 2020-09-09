class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0,j = 0, k = 0;
        vector<int> n1 = nums1;
        while(i<m && j < n) {
            if(nums1[i] < nums2[j]) {
                n1[k] = nums1[i];
                ++k;
                ++i;
            } else if(nums1[i] > nums2[j]) {
                n1[k] = nums2[j];
                ++k;
                ++j;
            } else {
                n1[k] = nums1[i];
                ++k;
                ++i;
                n1[k] = nums2[j];
                ++k;
                ++j;
            }
        }
        while(i<m) {
            n1[k] = nums1[i];
            ++k;
            ++i;
        }
        while(j<n) {
            n1[k] = nums2[j];
            ++k;
            ++j;
        }
        nums1 = n1;
    }
};