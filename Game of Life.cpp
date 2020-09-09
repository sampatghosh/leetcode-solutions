class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int live = 2, die = 3;
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                int count = 0;
                if(i > 0) {
                    if(j < board[i].size()-1)
                        count+=board[i-1][j+1] < 2?board[i-1][j+1]:board[i-1][j+1]-2;
                    if(j > 0)
                        count+=board[i-1][j-1] < 2?board[i-1][j-1]:board[i-1][j-1]-2;
                    count += board[i-1][j] < 2?board[i-1][j]:board[i-1][j]-2;
                }
                if(j < board[i].size()-1)
                    count+=board[i][j+1] < 2?board[i][j+1]:board[i][j+1]-2;
                if(j > 0)
                    count+=board[i][j-1] < 2?board[i][j-1]:board[i][j-1]-2;
                if(i < board.size()-1) {
                    if(j < board[i].size()-1)
                        count+=board[i+1][j+1] < 2?board[i+1][j+1]:board[i+1][j+1]-2;
                    if(j > 0)
                        count+=board[i+1][j-1] < 2?board[i+1][j-1]:board[i+1][j-1]-2;
                    count += board[i+1][j] < 2?board[i+1][j]:board[i+1][j]-2;
                }
                if(board[i][j] == 1) {
                    if(count<2 || count > 3)
                        board[i][j] = 3;
                } else {
                    if(count == 3)
                        board[i][j] = 2;
                }
            }
        }
        for(int i = 0; i < board.size(); ++i)
            for(int j = 0; j < board[i].size(); ++j)
                if(board[i][j] == 2)
                    board[i][j]=1;
                else if(board[i][j] == 3)
                    board[i][j] = 0;
    }
};