class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> out,degree(numCourses,0);
        vector<vector<int>> adj(numCourses, vector<int>());
        for (auto edge: prerequisites) {
            adj[edge[1]].push_back(edge[0]);
            ++degree[edge[0]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (degree[i] == 0) {
                q.push(i);
                out.push_back(i);
            }
        }
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            --numCourses;
            for (auto i : adj[curr])
                if (--degree[i] == 0) {
                    out.push_back(i);
                    q.push(i);
                }
        }
        if(numCourses == 0)
            return out;
        else
            return {};
    }
};