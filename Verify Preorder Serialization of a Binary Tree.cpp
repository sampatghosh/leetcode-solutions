class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<char> stk;
        string str = "";
        for(int i=0;i<preorder.length();++i) {
            if(preorder[i]!=',')
                str+=preorder[i];
            if(preorder[i]==',' || i == preorder.length()-1){
                if (str != "#") {
                    stk.push('i');
                }
                else {
                    while (!stk.empty() && stk.top() == '#') {
                        stk.pop();
                        if (stk.empty()) {
                            return false;
                        }
                        stk.pop();
                    }
                    stk.push('#');
                }
                str = "";
            }
        }
        if(stk.size()==1 && stk.top()=='#')
            return true;
        else
            return false;

    }
};