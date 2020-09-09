struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int out = 0;
        for(int i = 0; i < points.size(); ++i) {
            unordered_map<pair<int, int>, int, hash_pair> mp;
            int res = 0, up = 0, overlap = 0;
            for(int j = i + 1; j < points.size(); ++j) {
                if(points[i] == points[j])
                    ++overlap;
                else if(points[i][0] == points[j][0])
                    ++up;
                else {
                    int x = points[i][0] - points[j][0];
                    int y = points[i][1] - points[j][1];
                    int g = __gcd(x,y);
                    mp[make_pair(x/g,y/g)]++;
                    res = max(res,mp[make_pair(x/g,y/g)]);
                }
                res = max(res, up);
            }
            out = max(out,res+overlap+1);
        }
        return out;
    }
};