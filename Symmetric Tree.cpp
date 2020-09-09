class Solution {
public:
    bool flag = true;
    void order(TreeNode *l,TreeNode *r) {
        if(l && r) {
            order(l->right,r->left);
            if(l->val!=r->val) {
                flag = false;
                return;
            }
            order(l->left,r->right);
        } else if((l && !r) || (!l && r)) {
            flag = false;
            return;
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(!root || (!root->left && !root->right))
            return flag;
        TreeNode *l = root->left;
        TreeNode *r = root->right;
        order(l,r);
        return flag;
    }
};