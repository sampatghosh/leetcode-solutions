class Solution {
public:
    void invert(TreeNode* t) {
        if(t==NULL)
            return;
        invert(t->left);
        invert(t->right);
        auto temp = t->left;
        t->left = t->right;
        t->right = temp;
    }
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};