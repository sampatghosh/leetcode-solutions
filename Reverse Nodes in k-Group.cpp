class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==0 || head->next==NULL)
            return head;
        ListNode *t, *temp;
        t = head;
        stack<int> stk;
        int i=0;
        while(t) {
            temp=t;
            i=0;
            while(temp && i<k) {
                stk.push(temp->val);
                ++i;
                temp=temp->next;
            }
            if(i==k) {
                while(!stk.empty()) {
                    t->val = stk.top();
                    t = t->next;
                    stk.pop();
                }
            }
            else
                t=temp;
        }
        return head;
    }
};