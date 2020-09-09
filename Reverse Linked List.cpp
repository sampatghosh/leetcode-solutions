class Solution {
public:
    ListNode* out;
    void rev(ListNode* prev, ListNode* curr) {
        if(curr) {
            rev(curr,curr->next);
            curr->next = prev;
        } else
            out = prev;
    }
    ListNode* reverseList(ListNode* head) {
        rev(NULL,head);
        return out;
    }
};