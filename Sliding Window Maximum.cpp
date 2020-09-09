class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> out;
        if(nums.size()==0)
            return out;
        int max = nums[0], id = 0;
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < k; ++i)
            pq.push({nums[i],i});
        out.push_back(pq.top().first);
        for(int i = k; i < nums.size(); ++i) {
            while(!pq.empty() && pq.top().second < i-k+1)
                pq.pop();
            pq.push({nums[i],i});
            out.push_back(pq.top().first);
        }
        return out;
    }
};