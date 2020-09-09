class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head)
            return nullptr;
        ListNode *less = nullptr, *more = nullptr, *t = head, *mhead = nullptr;
        while(t) {
            if(t->val < x) {
                if(!less) {
                    less = t;
                    head = less;
                }
                else {
                    less->next = t;
                    less = less->next;
                }
            } else {
                if(!more) {
                    more = t;
                    mhead = more;
                }
                else {
                    more->next = t;
                    more = more->next;
                }
            }
            t = t->next;
            if(more)
                more->next = nullptr;
            if(less)
                less->next = nullptr;
        }
        if(less && mhead)
            less->next = mhead;
        return head;
    }
};