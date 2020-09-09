class Solution {
public:
    TreeNode* helper(ListNode* head, ListNode *tail) {
        ListNode *rabbit = head, *tortoise = head;
        TreeNode *root = nullptr;
        if(head == tail)
            return root;
        if(head->next == tail) {
            root = new TreeNode(head->val,nullptr,nullptr);
            return root;
        }
        while(rabbit!=tail && rabbit->next!=tail) {
            rabbit = rabbit->next->next;
            tortoise = tortoise->next;
        }
        root = new TreeNode(tortoise->val);
        root->left = helper(head, tortoise);
        root->right = helper(tortoise->next, tail);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head,nullptr);
    }
};