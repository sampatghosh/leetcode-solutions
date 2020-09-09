class Solution {
public:
    int numSquares(int amount) {
        vector<int> arr;
        for(int i = 1; i <= amount; ++i) {
            if(sqrt(i)-floor(sqrt(i)) == 0)
                arr.push_back(i);
        }
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i) {
            if(sqrt(i)-floor(sqrt(i)) == 0) {
                arr.push_back(i);
                dp[i] = 1;
                continue;
            }
            for(int j = 0;j < arr.size(); ++j) {
                if(arr[j] <= i)
                    dp[i] = min(dp[i],1+dp[i-arr[j]]);
                else
                    break;
            }
        }
        if(dp[amount]>amount)
            return -1;
        else
            return dp[amount];
    }
};