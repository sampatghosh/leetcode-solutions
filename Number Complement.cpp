class Solution {
public:
    int findComplement(int num) {
        if(num == 0)
            return 1;
        stack<int> stk;
        while(num!=0) {
            stk.push(num%2);
            num = num >> 1;
        }
        int ans=0;
        while(!stk.empty()) {
            ans = ans << 1;
            if(stk.top()==0)
                ans = ans | 1;
            stk.pop();
        }
        return ans;
    }
};