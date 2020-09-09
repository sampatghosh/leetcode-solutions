class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> out;
        queue<TreeNode*> q;
        if (root) {
            q.push({root});
            out.push_back({root->val});
        }
        int flag = 0;
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
            if(temp.size()) {
                if(flag) {
                    out.push_back(temp);
                    flag = 0;
                } else {
                    out.push_back({temp.rbegin(),temp.rend()});
                    flag = 1;
                }
            }
        }
        return out;
    }
};