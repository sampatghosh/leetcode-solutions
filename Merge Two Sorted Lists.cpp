class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *t=NULL, *n, *head=NULL;
        while(l1 && l2) {
            n = new ListNode();
            if(l1->val < l2->val) {
                n -> val = l1 -> val;
                if(t == NULL) {
                    t = n;
                    head = t;
                }
                else {
                    t -> next = n;
                    t = t -> next;
                }
                l1 = l1 -> next;
            }
            else if(l1->val > l2->val) {
                n -> val = l2 -> val;
                if(t == NULL) {
                    t = n;
                    head = t;
                }
                else {
                    t -> next = n;
                    t = t -> next;
                }
                l2 = l2 -> next;
            }
            else {
                ListNode *temp = new ListNode();
                n -> val = temp-> val = l2 -> val;
                n -> next = temp;
                if(t == NULL) {
                    t = n;
                    head = t;
                    t = t -> next;
                }
                else {
                    t -> next = n;
                    t = t -> next -> next;
                }
                l2 = l2 -> next;
                l1 = l1 -> next;
            }
        }
        if(!l1) {
            while(l2) {
                n = new ListNode();
                n -> val = l2 -> val;
                if(t == NULL) {
                    t = n;
                    head = t;
                }
                else {
                    t -> next = n;
                    t = t -> next;
                }
                l2 = l2 -> next;
            }
        }
        else if(!l2) {
            while(l1) {
                n = new ListNode();
                n -> val = l1 -> val;
                if(t == NULL) {
                    t = n;
                    head = t;
                }
                else {
                    t -> next = n;
                    t = t -> next;
                }
                l1 = l1 -> next;
            }
        }
        return head;
    }
};