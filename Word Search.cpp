class Solution {
public:
    bool check(vector<vector<char>>& board, int i, int j, string word, int pos,vector<vector<int>>& visited) {
        if(pos < word.length()-1) {
            if(j+1 < board[i].size() && board[i][j+1]==word[pos+1] && visited[i][j+1]==0) {
                visited[i][j+1] = 1;
                bool ret = check(board,i,j+1,word,pos+1,visited);
                if(ret == true)
                    return true;
                else
                    visited[i][j+1] = 0;
            }
            if(i+1 < board.size() && board[i+1][j]==word[pos+1] && visited[i+1][j]==0) {
                visited[i+1][j] = 1;
                bool ret = check(board,i+1,j,word,pos+1,visited);
                if(ret == true)
                    return true;
                else
                    visited[i+1][j] = 0;
            }
            if(j-1 >= 0 && board[i][j-1]==word[pos+1] && visited[i][j-1]==0) {
                visited[i][j-1] = 1;
                bool ret = check(board,i,j-1,word,pos+1,visited);
                if(ret == true)
                    return true;
                else
                    visited[i][j-1] = 0;
            }
            if(i-1 >= 0 && board[i-1][j]==word[pos+1] && visited[i-1][j]==0) {
                visited[i-1][j] = 1;
                bool ret = check(board,i-1,j,word,pos+1,visited);
                if(ret == true)
                    return true;
                else
                    visited[i-1][j] = 0;
            }
            return false;
        }
        else
            return true;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector< pair<int,int> >start;
        vector<vector<int>> visited(board.size());
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0;j < board[i].size();++j) {
                if(board[i][j]==word[0]) {
                    start.push_back(make_pair(i,j));
                }
                visited[i].push_back(0);
            }
        }
        for(auto i : start) {
            visited[i.first][i.second] = 1;
            bool t = check(board, i.first, i.second, word, 0, visited);
            if(t == true)
                return true;
            else
                visited[i.first][i.second] = 0;

        }
        return false;
    }
};