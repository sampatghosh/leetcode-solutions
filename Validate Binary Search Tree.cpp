class Solution {
public:
    TreeNode *prev = nullptr;
    bool helper(TreeNode* node) {
        if(!node)
            return true;
        bool left =helper(node->left);
        if(prev and prev->val >= node->val)
            return false;
        prev = node;
        bool right = helper(node->right);
        return left and right;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root);
    }
};