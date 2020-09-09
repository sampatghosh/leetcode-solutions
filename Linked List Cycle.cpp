class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)
            return false;
        ListNode *t = head, *r = head->next->next;
        while(r && r->next && r!=t) {
            r = r->next->next;
            t = t->next;
        }
        if (r == t)
            return true;
        return false;
    }
};