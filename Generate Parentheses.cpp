class Solution {
public:
    vector<string> out;
    void solve(string s, int left, int right) {
        if(left==right) {
            if(left==0)
                out.push_back(s);
            else {
                s = s + '(';
                solve(s,left-1,right);
            }
        } else if (left < right) {
            if(left==0) {
                s = s + ')';
                solve(s,left,right-1);
            } else {
                solve(s+'(',left-1,right);
                solve(s+')',left,right-1);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        ios_base::sync_with_stdio(false);
        solve("", n, n);
        return out;
    }
};