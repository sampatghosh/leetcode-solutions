class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& num1, vector<int>& num2, int k) {
        vector<vector<int>> out;
        if(num1.size()==0 || num2.size()==0)
            return out;
        auto compare = [&num1, &num2](pair<int,int>& a, pair<int,int>& b) {
            return num1[a.first] + num2[a.second] > num1[b.first] + num2[b.second];
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(compare)> pq(compare);
        pq.push(make_pair(0,0));
        while(!pq.empty() && --k >= 0) {
            auto t = pq.top();
            pq.pop();
            out.push_back({num1[t.first],num2[t.second]});
            if(t.first == 0 && t.second < num2.size()-1)
                pq.push(make_pair(t.first,t.second+1));
            if(t.first < num1.size()-1)
                pq.push(make_pair(t.first+1,t.second));
        }
        return out;
    }
};