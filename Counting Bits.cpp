class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> out(num+1,0);
        for(int i = 1; i <= num; ++i)
            out[i] =  out[i & (i-1)] + 1;
        return out;

    }
};