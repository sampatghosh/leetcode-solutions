class Solution {
    int count=0, out=-1;
public:
    void find(TreeNode* root, int k) {
        if(root) {
            find(root->left,k);
            ++count;
            if(count == k) {
                out  = root -> val;
                return;
            }
            find(root->right,k);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        find(root,k);
        return out;
    }
};