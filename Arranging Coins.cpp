class Solution {
public:
    int arrangeCoins(int n) {
        long long int i = 1, res = 0;
        while((i*(i+1))/2 <= n) {
            res = i;
            ++i;
        }
        return res;
    }
};