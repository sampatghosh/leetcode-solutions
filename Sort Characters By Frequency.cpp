bool sortByVal(const pair<int,int>& a,const pair<int,int>& b) {
    return a.second > b.second;
}
class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, int>> v(255);
        for(char c : s) {
            v[c].first = c;
            ++v[c].second;
        }
        sort(v.begin(),v.end(),sortByVal);
        s = "";
        for(auto i:v) {
            if(i.second > 0)
                for(int j = 1; j <= i.second; ++j)
                    s += i.first;
        }
        return s;
    }
};