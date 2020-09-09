class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> out;
        if(matrix.size()==0)
            return out;
        int r = matrix.size();
        int c = matrix[0].size();
        int i = 0, j = 0;
        int n = matrix.size()*matrix[0].size();
        while(out.size()<n) {
            for(int j1 = j; j1 < c; ++j1)
                out.push_back(matrix[i][j1]);
            if(out.size()==n)
                break;
            for(int i1 = i+1; i1 < r; ++i1)
                out.push_back(matrix[i1][c-1]);
            if(out.size()==n)
                break;
            for(int j1 = c-2; j1 >= j; --j1)
                out.push_back(matrix[r-1][j1]);
            if(out.size()==n)
                break;
            for(int i1 = r-2; i1 > i; --i1)
                out.push_back(matrix[i1][j]);
            ++i;++j;--c;--r;
        }
        return out;
    }
};