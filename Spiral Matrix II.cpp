class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int x = 1, r1 = 0, r2 = n-1, c1 = 0, c2 = n-1;
        while(x <= n*n) {
            for(int i = c1; i <= c2; ++i)
                matrix[r1][i] = x++;
            for(int j = r1+1; j <= r2; ++j)
                matrix[j][c2] = x++;
            for(int i = c2-1; i >= c1; --i)
                matrix[r2][i] = x++;
            for(int j = r2-1; j >= r1+1; --j)
                matrix[j][c1] = x++;
            ++r1;
            --r2;
            ++c1;
            --c2;
        }
        return matrix;
    }
};