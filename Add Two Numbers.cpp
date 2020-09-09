class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode *head ;
        head = new ListNode();
        int carry = (l1->val + l2->val)/10;
        head->val = (l1->val + l2->val)%10;
        l1=l1->next;
        l2=l2->next;
        ListNode* t=head;
        struct ListNode* new_node;
        while(l1!=NULL || l2!=NULL) {
            new_node =new ListNode();
            if(l1==NULL) {
                int temp = (l2->val + carry);
                new_node->val = temp%10;
                carry = temp/10;
                t->next = new_node;
                t = t->next;
                l2=l2->next;
            }
            else if(l2==NULL) {
                int temp = (l1->val + carry);
                new_node->val = temp%10;
                carry = temp/10;
                t->next = new_node;
                t = t->next;
                l1=l1->next;
            }
            else {
                int temp = (l1->val + l2->val + carry);
                new_node->val = temp%10;
                carry = temp/10;
                t->next = new_node;
                t = t->next;
                l1=l1->next;
                l2=l2->next;
            }
        }
        if(carry!=0) {
            struct ListNode* new_node =new ListNode();
            new_node->val = carry;
            t->next = new_node;
        }
        return head;
    }
};