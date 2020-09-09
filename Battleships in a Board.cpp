class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if(board.size()==0 || board[0].size()==0)
            return 0;
        int ship = 0;
        vector<vector<int>> mp(board.size(),vector<int>(board[0].size(), 0));
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(board[i][j]=='X') {
                    if(i==0) {
                        if(j > 0) {
                            if(board[i][j-1]=='X')
                                mp[i][j] = mp[i][j-1];
                            else
                                mp[i][j] = ++ship;
                        } else
                            mp[i][j] = ++ship;
                    } else {
                        if(j > 0) {
                            if(board[i][j-1]=='X')
                                mp[i][j] = mp[i][j-1];
                            else if(board[i-1][j]=='X')
                                mp[i][j] = mp[i-1][j];
                            else
                                mp[i][j] = ++ship;
                        } else if(board[i-1][j]=='X')
                            mp[i][j] = mp[i-1][j];
                        else
                            mp[i][j] = ++ship;
                    }
                }
            }
        }
        return ship;
    }
};