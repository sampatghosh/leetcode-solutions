class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int> > edges;
        for(int i = 0; i < buildings.size(); ++i) {
            edges.push_back({buildings[i][0],buildings[i][2],1});
            edges.push_back({buildings[i][1],buildings[i][2],2});
        }
        sort(edges.begin(),edges.end(),[](vector<int> &a, vector<int> &b) {
            if(a[0] != b[0])
                return a[0] < b[0];
            if(a[2] == 1 && b[2] == 1)
                return a[1] > b[1];
            if(a[2] == 2 and b[2] == 2)
                return a[1] < b[1];
            return a[2] == 1 ? true : false;
        });
        vector<vector<int>> out;
        multiset<int> mul;
        mul.insert(0);
        for(int i = 0; i < edges.size(); ++i) {
            int top = *(mul.rbegin());
            if(edges[i][2]==1) {
                mul.insert(edges[i][1]);
                if(*(mul.rbegin()) != top)
                    out.push_back({edges[i][0],edges[i][1]});

            } else {
                mul.erase(mul.find(edges[i][1]));
                if(*(mul.rbegin())!=top)
                    out.push_back({edges[i][0],*(mul.rbegin())});
            }
        }
        return out;
    }
};