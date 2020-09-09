class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        string out = "", temp = "";
        for(int i = 0; i < path.length(); ++i) {
            if(path[i] != '/')
                temp+=path[i];
            else {
                if(temp=="..") {
                    if(stk.size()>1)
                        stk.pop();
                    while(!stk.empty() && stk.top() != "/")
                        stk.pop();
                    temp = "";
                } else if(temp==".")
                    temp = "";
                else if(temp=="") {
                    if(stk.empty())
                        stk.push("/");
                } else {
                    stk.push(temp);
                    temp = "";
                    stk.push("/");
                }
            }
        }
        if(temp == "..") {
            if(stk.size()>1)
                stk.pop();
            while(!stk.empty() && stk.top() != "/")
                stk.pop();
        } else if(temp != "" && temp !=".") {
            stk.push(temp);
            stk.push("/");
        }
        if(stk.size() > 1 && stk.top()=="/")
            stk.pop();
        while(!stk.empty()) {
            out = stk.top() + out;
            stk.pop();
        }
        return out;
    }
};