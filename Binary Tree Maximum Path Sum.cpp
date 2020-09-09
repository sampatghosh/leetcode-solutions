class Solution {
public:
    int maxi = INT_MIN;
    int check(TreeNode* t) {
        if(t==NULL)
            return 0;
        int l = max(0,check(t->left));
        int r = max(0,check(t->right));

        int temp = t->val+max(l,r);

        maxi=max(l+r+t->val,maxi);

        return temp>0?temp:0;
    }
    int maxPathSum(TreeNode* root) {
        check(root);
        return maxi;
    }
};