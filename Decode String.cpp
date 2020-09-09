class Solution {
public:
    string decodeString(string s) {
        string temp = "", stk = "";
        for(int i = 0; i < s.length(); ++i) {
            if(s[i]!=']')
                stk.push_back(s[i]);
            else {
                while(stk.back()!='[') {
                    temp = stk.back() + temp;
                    stk.pop_back();
                }
                stk.pop_back();
                string count = "";
                while(stk.length() && stk.back()>='0' && stk.back()<='9') {
                    count = stk.back() + count;
                    stk.pop_back();
                }
                for(int i = 1; i <= stoi(count);++i) {
                    stk += temp;
                }
                temp = "";
            }
        }
        return stk;
    }
};