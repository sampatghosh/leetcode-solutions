class Solution {
public:
    void backtrack(TreeNode *t, vector<int>& out, int *level, int curr) {
        if(t) {
            if(*level < curr && t) {
                out.push_back(t->val);
                ++*level;
            }
            backtrack(t->right,out,level,curr+1);
            backtrack(t->left,out,level,curr+1);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
            return {};
        vector<int> out;
        int level = 0;
        backtrack(root,out,&level,1);
        return out;
    }
};