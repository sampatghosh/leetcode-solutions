class Solution {
public:
    int diff(string a,string b) {
        int ans = 0;
        for(int i = 0; i < a.length(); ++i)
            if(a[i] != b[i])
                ++ans;
        return ans;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<pair<string,int>,int>> q;
        vector<bool> visited(wordList.size(),false);
        vector<vector<int>> change(wordList.size(),vector<int>());
        unordered_map<string,int> mp;
        for(int i = 0; i < wordList.size(); ++i)
            mp[wordList[i]] = i;
        for(int i = 0; i < wordList.size(); ++i) {
            for(int j = 0; j < wordList[i].length();++j) {
                for(char k = 'a'; k <= 'z'; ++k) {
                    string temp = wordList[i];
                    if(k!=temp[j]) {
                        temp[j] = k;
                        if(mp.find(temp)!=mp.end()) {
                            change[i].push_back(mp[temp]);
                            // change[mp[temp]].push_back(i);
                        }
                    }
                }
            }
            if(diff(beginWord,wordList[i])==1) {
                q.push({{wordList[i],1},i});
            }

        }
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            if(top.first.first==endWord)
                return top.first.second+1;
            if(!visited[top.second]) {
                visited[top.second] = true;
                for(int i = 0; i < change[top.second].size(); ++i) {
                    int id = change[top.second][i];
                    if(!visited[id])
                        q.push({{wordList[id],top.first.second+1},id});
                }
            }
        }
        return 0;
    }
};