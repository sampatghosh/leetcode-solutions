class Solution {
public:
    int maxProfit(vector<int>& prizes) {
        int profit=0;
        int buy=-1;
        int x=0;
        int i=0;
        while(x<prizes.size()) {
            for(i=x;i<prizes.size()-1;++i) {
                if(prizes[i]<prizes[i+1])
                    break;
            }
            if(i==prizes.size()-1)
                break;
            else {
                int j=0;
                buy=prizes[i];
                for(j=i;j<prizes.size()-1;++j) {
                    if(prizes[j]>prizes[j+1])
                        break;
                }
                profit += prizes[j]-buy;
                buy=-1;
                x=j+1;
            }
        }
        return profit;
    }
};