class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if(head->next==NULL)
            return head;
        ListNode *curr = head->next, *prev = head, *next;
        prev->next = NULL;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL)
            return true;
        ListNode* tortoise = head;
        ListNode* rabbit = head;
        while(rabbit && rabbit->next) {
            tortoise = tortoise->next;
            rabbit = rabbit->next->next;
        }
        rabbit = head;
        tortoise  = reverse(tortoise);
        while(rabbit && tortoise) {
            if(rabbit->val!=tortoise->val)
                return false;
            rabbit = rabbit -> next;
            tortoise = tortoise -> next;
        }
        return true;
    }
};