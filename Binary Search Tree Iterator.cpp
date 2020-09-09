class BSTIterator {
private:
    stack<TreeNode*> stk;
public:
    BSTIterator(TreeNode* root) {
        if(root) {
            stk.push(root);
            goLeft();
        }
    }

    void goLeft() {
        while(stk.top()->left) {
            stk.push(stk.top()->left);
        }
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* temp = stk.top();
        stk.pop();
        int out = temp->val;
        if(!stk.empty() && stk.top()->left && stk.top()->left==temp)
            stk.top()->left = NULL;
        if(temp->right) {
            stk.push(temp->right);
            goLeft();
        } else if(temp->left) {
            stk.push(temp->left);
            goLeft();
        }
        return out;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }
};