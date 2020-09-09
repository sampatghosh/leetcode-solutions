class Solution {
public:
    vector<vector<string>> out;
    bool valid(vector<string>& board, int i, int j) {
        int x = i-1,  y = j-1;
        while(x >= 0 && y >= 0) {
            if(board[x][y] == 'Q')
                return false;
            --x;
            --y;
        }
        x = i - 1;
        y = j + 1;
        while(x >= 0 && y < board.size()) {
            if(board[x][y] == 'Q')
                return false;
            --x;
            ++y;
        }
        for(int k = 0; k < i; ++k) {
            if(board[k][j] == 'Q')
                return false;
        }
        return true;
    }
    void backtrack(vector<string>& board, int row) {
        if(row == board.size()) {
            out.push_back(board);
            return;
        }
        else {
            for(int j = 0; j < board.size(); ++j) {
                board[row][j] = 'Q';
                if(valid(board,row,j))
                    backtrack(board,row+1);
                board[row][j] = '.';
            }
            return;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        ios_base::sync_with_stdio(false);
        vector<string> board;
        string x;
        for(int i = 0; i < n; ++i)
            x.push_back('.');
        for(int i = 0; i < n; ++i)
            board.push_back(x);
        backtrack(board,0);
        return out;
    }
};