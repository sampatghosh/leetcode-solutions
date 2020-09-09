class Solution {
public:
    int nthUglyNumber(int n) {
        int i = 0, j = 0, k = 0;
        vector<int> dp;
        dp.push_back(1);
        int count = 1;
        while(count < n) {
            dp.push_back(min({2*dp[i], 3*dp[j], 5*dp[k]}));
            if(dp[count] == dp[i]*2)
                ++i;
            if(dp[count] == dp[j]*3)
                ++j;
            if(dp[count] == dp[k]*5)
                ++k;
            ++count;
        }
        return dp[n-1];
    }
};