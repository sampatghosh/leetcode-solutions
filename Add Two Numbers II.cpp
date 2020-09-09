class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stk1,stk2;
        while(l1) {
            stk1.push(l1->val);
            l1 = l1 -> next;
        }
        while(l2) {
            stk2.push(l2->val);
            l2 = l2 -> next;
        }
        ListNode *head = NULL;
        int carry = 0;
        while(!stk1.empty() && !stk2.empty()) {
            int temp = stk1.top()+stk2.top()+carry;
            carry = temp / 10;
            if(head==NULL) {
                head = new ListNode();
                head->val = temp % 10;
            } else {
                ListNode *t = new ListNode();
                t->val = temp % 10;
                t->next = head;
                head = t;
            }
            stk1.pop();
            stk2.pop();
        }
        while(!stk1.empty()) {
            int temp = stk1.top()+carry;
            carry = temp / 10;
            if(head==NULL) {
                head = new ListNode();
                head->val = temp % 10;
            } else {
                ListNode *t = new ListNode();
                t->val = temp % 10;
                t->next = head;
                head = t;
            }
            stk1.pop();
        }
        while(!stk2.empty()) {
            int temp = stk2.top()+carry;
            carry = temp / 10;
            if(head==NULL) {
                head = new ListNode();
                head->val = temp % 10;
            } else {
                ListNode *t = new ListNode();
                t->val = temp % 10;
                t->next = head;
                head = t;
            }
            stk2.pop();
        }
        if(carry!=0) {
            if(head==NULL) {
                head = new ListNode();
                head->val = carry;
            } else {
                ListNode *t = new ListNode();
                t->val = carry;
                t->next = head;
                head = t;
            }
        }
        return head;
    }
};