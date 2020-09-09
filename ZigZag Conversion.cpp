class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> out(numRows);
        int i = 0;
        while(i < s.length()) {
            for(int j = 0; j < numRows and i < s.length();++j)
                out[j].push_back(s[i++]);
            if(i >= s.length())
                break;
            for(int j = numRows-2; j >= 1 and i < s.length(); --j)
                out[j].push_back(s[i++]);
        }
        string ans = "";
        for(string i : out)
            ans += i;
        return ans;
    }
};