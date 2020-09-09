class NumMatrix {
public:
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>>& matrix) {
        mat = matrix;
        if(matrix.size() && matrix[0].size()) {
            mat[0][0] = matrix[0][0];
            for(int i = 1; i < matrix[0].size(); ++i)
                mat[0][i] = matrix[0][i] + mat[0][i-1];
            for(int i = 1; i < matrix.size(); ++i)
                mat[i][0] = matrix[i][0] + mat[i-1][0];
            for(int i = 1; i < matrix.size(); ++i)
                for(int j = 1; j < matrix[i].size(); ++j)
                    maat[i][j] = mat[i][j-1] + mat[i-1][j] - mat[i-1][j-1] + matrix[i][j];
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int left = 0, up = 0;
        if(col1 > 0) {
            left = mat[row2][col1-1];
            if(row1 > 0) {
                left -= mat[row1-1][col1-1];
            }
        }
        if(row1 > 0)
            up = mat[row1-1][col2];
        return mat[row2][col2] - left - up;

    }
};