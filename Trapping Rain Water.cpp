class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0)
            return 0;
        int ans=0;
        vector<int> left(height.size()),right(height.size());
        left[0] = height[0];
        int n = height.size();
        for(int i = 1; i < n; ++i)
            left[i] = max(left[i-1],height[i]);
        right[n-1] = height[n-1];
        for(int i = n-2; i >- 0; --i) {
            right[i] = max(right[i+1],height[i]);
        }
        for(int i = 1; i < n-1; ++i)
            ans += min(left[i],right[i])-height[i];
        return ans;
    }
};