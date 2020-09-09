class Solution {
public:
    int max(int a, int b) {
        return (a > b)? a : b;
    }
    int max(int a, int b, int c) {
        return max(max(a, b), c);
    }
    int maxSubArray(vector<int>& nums) {
        return maxSum(nums,0,nums.size()-1);
    }
    int maxSum(vector<int>& arr,int l,int h) {
        if(l == h)
            return arr[l];
        int m=(l+h)/2;
        return max(maxSum(arr, l, m),maxSum(arr, m+1, h),
                   maxCrossingSum(arr, l, m, h));
    }
    int maxCrossingSum(vector<int>& arr, int l, int m, int h) {
        int sum = 0;
        int left_sum = INT_MIN;
        for (int i = m; i >= l; i--) {
            sum = sum + arr[i];
            if (sum > left_sum)
                left_sum = sum;
        }
        sum = 0;
        int right_sum = INT_MIN;
        for (int i = m+1; i <= h; i++) {
            sum = sum + arr[i];
            if (sum > right_sum)
                right_sum = sum;
        }
        return left_sum + right_sum;
    }
};