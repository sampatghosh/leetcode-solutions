class Trie {
public:
    Trie *next[26]={NULL};
    bool end = false;
    string s = "";
};
class Solution {
public:
    void search(Trie *t, int i, int j, vector<vector<char>>& board,
                vector<vector<char>>& visited, set<string>& out) {
        if(visited[i][j]=='+' && t) {
            visited[i][j] = '-'; // for marking that this pos is visited
            if(t->end) //for checking if we have reached the end of an input word
                out.insert(t->s);
            if(j > 0) // left
                search(t->next[board[i][j-1]-'a'],i,j-1,board,visited,out);
            if(j < board[0].size()-1) // right
                search(t->next[board[i][j+1]-'a'],i,j+1,board,visited,out);
            if(i > 0) // up
                search(t->next[board[i-1][j]-'a'],i-1,j,board,visited,out);
            if(i < board.size()-1) // down
                search(t->next[board[i+1][j]-'a'],i+1,j,board,visited,out);
            visited[i][j]='+'; // unmarking for next iteration
        }
    }
    void insert(Trie *root, string s) {
        Trie *temp = root;
        for(int i = 0; i < s.length(); ++i) {
            if(temp->next[s[i]-'a']==NULL)
                temp->next[s[i]-'a'] = new Trie();
            temp = temp->next[s[i]-'a'];
        }
        temp->s = s;
        temp->end = true;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *root = new Trie();
        for(string w : words) //build trie using input words
            insert(root,w);
        set<string> out;
        vector<vector<char>> visited(board.size(),vector<char>(board[0].size(),'+'));
        for(int i = 0; i < board.size(); ++i)
            for(int j = 0; j < board[i].size(); ++j) {
                // backtrack using trie
                search(root->next[board[i][j]-'a'],i,j,board,visited,out);
            }
        vector<string> ans(out.size());
        copy(out.begin(),out.end(),ans.begin());
        return ans;
    }
};