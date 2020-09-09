class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.length())
            return "0";
        stack<char> stk;
        stk.push(num[0]);
        int i = 1;
        int k1 = k;
        for(i = 1; i < num.length(); ++i) {
            if(k==0)
                break;
            if(stk.top()>num[i]) {
                while(k>0 && !stk.empty() && stk.top()>num[i]) {
                    stk.pop();
                    k--;
                }
            }
            stk.push(num[i]);
        }
        if(k1 == k)
            return num.substr(0,num.length()-k);
        else {
            if(k!=0) {
                while(k!=0) {
                    stk.pop();
                    --k;
                }
            }
            string s ="";
            while(!stk.empty()) {
                s = stk.top()+s;
                stk.pop();
            }
            s = s + num.substr(i,num.length()-1);
            if(s.length()==0)
                return "0";
            else {
                int j = 0;
                for(j = 0;j < s.length() && s[j]=='0';++j);
                if(j==s.length())
                    return "0";
                else
                    return s.substr(j,num.length()-1);
            }
        }
    }
};