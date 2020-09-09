class Solution {
public:
    bool check(int v, vector<vector<int> >& adj, vector<int>& visited) {
        if(visited[v]==1)
            return true;
        if(visited[v]==0) {
            visited[v]=1;
            for(auto i : adj[v]) {
                if(check(i,adj,visited))
                    return true;
            }
        }
        visited[v] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > adj(numCourses);
        for(int i = 0; i < prerequisites.size(); ++i)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);

        vector<int> visited(numCourses,0);

        for(int i = 0; i < numCourses; ++i) {
            if(check(i,adj,visited))
                return false;
        }
        return true;
    }
};