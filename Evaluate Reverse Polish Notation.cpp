class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> stk;
        for(int i = 0; i < tokens.size(); ++i) {
            if(tokens[i] != "*" && tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "/")
                stk.push(tokens[i]);
            else {
                int b = stoi(stk.top());
                stk.pop();
                int a = stoi(stk.top());
                stk.pop();
                switch(tokens[i][0]) {
                    case '+' : stk.push(to_string(a+b)); break;
                    case '-' : stk.push(to_string(a-b)); break;
                    case '*' : stk.push(to_string(a*b)); break;
                    case '/' : stk.push(to_string(a/b)); break;
                }
            }
        }
        return stoi(stk.top());
    }
};