class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, max = 0;
        while(l<r) {
            int temp = (r - l)*min(height[l],height[r]);
            if(temp>max)
                max = temp;
            if(height[l]<height[r])
                ++l;
            else
                --r;
        }
        return max;
    }
};