class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(n!=1) {
            if(s.find(n)==s.end()) {
                s.insert(n);
                int n1 = n;
                n = 0;
                while(n1!=0) {
                    n += pow(n1%10,2);
                    n1 = n1 / 10;
                }
            } else
                return false;
        }
        return true;
    }
};