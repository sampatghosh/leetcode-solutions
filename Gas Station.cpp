class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int out = 0, total = 0, gasSum = 0, costSum = 0;
        for(int i = 0; i < gas.size(); ++i) {
            gasSum += gas[i];
            costSum += cost[i];
            total += (gas[i] - cost[i]);
            if(total < 0) {
                out = i + 1;
                total = 0;
            }
        }
        if(gasSum < costSum)
            return -1;
        return out;
    }
};