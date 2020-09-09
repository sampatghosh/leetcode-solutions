class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        vector<int> *temp;
        int n;
        TreeNode* t;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            temp = new vector<int>;
            n = q.size();
            for(int i = 0; i < n; ++i) {
                t = q.front();
                q.pop();
                temp->push_back(t->val);
                if(t->left != NULL) q.push(t->left);
                if(t->right != NULL) q.push(t->right);
            }
            ans.push_back(*temp);
            delete temp;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};