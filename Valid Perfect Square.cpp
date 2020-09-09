class Solution {
public:
    bool isPerfectSquare(int num) {
        return abs((double)sqrt(num)-(int)sqrt(num))==0;
    }
};