class NestedIterator {
public:
    vector<int> ans;
    int id = 0;
    NestedIterator(vector<NestedInteger> &nestedList) {
        helper(nestedList);
    }
    void helper(vector<NestedInteger> &nestedList) {
        for(int i = 0; i < nestedList.size(); ++i) {
            NestedInteger obj = nestedList[i];
            if (obj.isInteger())
                ans.push_back(obj.getInteger());
            else
                helper(obj.getList());
        }
    }
    int next() {
        return ans[id++];
    }

    bool hasNext() {
        if(id == ans.size())
            return false;
        return true;
    }
};
