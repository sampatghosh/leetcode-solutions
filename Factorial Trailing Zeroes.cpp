class Solution {
public:
    int trailingZeroes(int n) {
        int five = 0, two = 0;
        while (n >= 5) {
            five += floor(n/5);
            n = floor(n/5);
        }
        return five;
    }
};