class LRUCache {
public:
    int cap;
    list<pair<int,int>> lru;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    LRUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()) {
            auto it = mp[key];
            int val = it->second;
            lru.erase(it);

            lru.push_front({key,val});
            mp[key] = lru.begin();
            return val;
        }
        else
            return -1;
    }
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            auto it = mp[key];
            lru.erase(it);
        }
        else {
            if(mp.size() == cap) {
                auto temp = lru.rbegin();
                mp.erase(temp->first);
                lru.pop_back();
            }
        }
        lru.push_front({key, value});
        mp[key] = lru.begin();
    }
};