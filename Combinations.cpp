class Solution {
public:
    vector<vector<int>> out;
    void backtrack(int x, int n, vector<int> temp, int k) {
        if(temp.size() == k) {
            out.push_back(temp);
            return;
        }
        for(int i = x + 1; i <= n; ++i) {
            temp.push_back(i);
            backtrack(i,n,temp,k);
            temp.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        if(k > n)
            return {};
        vector<int> temp;
        backtrack(0,n,temp,k);
        return out;
    }
};