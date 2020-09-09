class Solution {
public:
    TreeNode* backtrack(TreeNode* t, TreeNode *p, TreeNode* q) {
        if (!t)
            return NULL;
        if (t == p || t == q)
            return t;
        TreeNode *leftz  = backtrack(t->left, p, q);
        TreeNode *right = backtrack(t->right, p, q);
        if (left && right)
            return t;
        return left ? left : right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* t, TreeNode* p, TreeNode* q) {
        ios_base::sync_with_stdio(false);
        return backtrack(t,p,q);
    }
};