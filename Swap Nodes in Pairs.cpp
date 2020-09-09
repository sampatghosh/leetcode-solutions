class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ios_base::sync_with_stdio(false);
        if(head==NULL || head->next==NULL)
            return head;
        if(head->next->next==NULL) {
            ListNode* t1 = head->next;
            head->next->next = head;
            head->next = NULL;
            return t1;
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        head = curr;
        while(curr && curr->next) {
            if(curr->next->next)
                prev->next = curr->next->next;
            else
                prev->next = curr->next;
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = temp;
            if(temp->next)
                curr = temp->next;
            else
                curr = NULL;
        }
        if(curr && curr->next==NULL) {
            curr->next = prev;
            prev->next = NULL;
        }
        return head;
    }
};