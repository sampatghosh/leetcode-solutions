class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> out;
        queue<TreeNode*> q;
        if (root) {
            q.push({root});
            out.push_back({root->val});
        }
        while (!q.empty()) {
            int n = q.size();
            vector<int> temp;
            for (int i = 0; i < n; ++i) {
                auto t = q.front();
                q.pop();
                if (t->left) {
                    q.push({t->left});
                    temp.push_back(t->left->val);
                }
                if (t->right) {
                    q.push({t->right});
                    temp.push_back(t->right->val);
                }
            }
            if(temp.size())
                out.push_back(temp);
        }
        return out;
    }
};