class Solution {
public:
    int areaFind(vector<int> heights) {
        int n = heights.size();
        if(n==0)
            return 0;
        int area = INT_MIN;
        stack<int> stk;
        for(int i = 0; i < n; ++i) {
            if(stk.empty() || heights[stk.top()] <= heights[i])
                stk.push(i);
            else {
                while(!stk.empty() && heights[stk.top()] > heights[i]) {
                    int t = stk.top();
                    stk.pop();
                    if(stk.empty())
                        area = max(area,heights[t]*i);
                    else {
                        /*
                            stk.top() gives the pos of the left most element
                            stk.top() below is used to figure out the left most pos
                            if the "t" is not immediately followed by t-1
                            this case will occur at 5th pos if we take the graph [2,1,5,6,2,3,2]
                            stack wil have [1,2 in it
                         */
                        area = max(area, (i-stk.top()-1)*heights[t]);
                    }
                }
                stk.push(i);
            }
        }
        while(!stk.empty()) {
            int t = stk.top();
            stk.pop();
            if(stk.empty())
                area = max(area, heights[t]*n);
            else
                area = max(area, (n-stk.top()-1)*heights[t]);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        int r = matrix.size(), c = matrix[0].size();
        int area = INT_MIN;
        vector<int> hist(c,0);
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(matrix[i][j] == '0')
                    hist[j] = 0;
                else
                    hist[j] += 1;
            }
            area = max(area,areaFind(hist));
        }
        return area;
    }
};