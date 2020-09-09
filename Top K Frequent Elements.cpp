class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> out;
        if(nums.size()==0)
            return out;
        unordered_map<int,int> mp;
        for(int i:nums)
            mp[i]++;
        auto comp = [](pair<int,int> &a, pair<int,int> &b) {return a.second > b.second;};
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
        for(auto i:mp) {
            if(pq.size() < k)
                pq.push(i);
            else {
                if(pq.top().second < i.second) {
                    pq.pop();
                    pq.push(i);
                }
            }
        }
        while(!pq.empty()) {
            out.push_back(pq.top().first);
            pq.pop();
        }
        return out;
    }
};