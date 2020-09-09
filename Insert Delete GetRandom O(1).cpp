class RandomizedSet {
private:
    unordered_map<int,int> mp;
public:
    RandomizedSet() {}
    bool insert(int val) {
        if(mp.find(val)==mp.end()) {
            mp[val]++;
            return true;
        } else
            return false;
    }
    bool remove(int val) {
        if(mp.find(val)==mp.end())
            return false;
        else {
            mp.erase(val);
            return true;
        }
    }
    int getRandom() {
        return next(mp.begin(),random()%mp.size())->first;
    }
};
