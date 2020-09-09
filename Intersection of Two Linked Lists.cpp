class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL)
            return NULL;
        stack<ListNode*> stk1, stk2;
        ListNode *t1 = headA, *t2 = headB;
        while(t1) {
            stk1.push(t1);
            t1 = t1 -> next;
        }
        while(t2) {
            stk2.push(t2);
            t2 = t2 -> next;
        }
        ListNode *out = NULL;
        while(!stk1.empty() && !stk2.empty() && stk1.top()==stk2.top()) {
            out = stk1.top();
            stk1.pop();
            stk2.pop();
        }
        return out;
    }
};