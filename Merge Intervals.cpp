class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> out;
        if(intervals.size()==0 || intervals[0].size()==0)
            return out;
        sort(intervals.begin(),intervals.end(),[](vector<int> &v1,vector<int> &v2) {
            return v1[0] < v2[0];});

        out.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i) {
            int res = out.size()-1;
            if(out[res][1] < intervals[i][0])
                out.push_back(intervals[i]);
            else
                out[res][1] = max(out[res][1],intervals[i][1]);
        }
        return out;

    }
};