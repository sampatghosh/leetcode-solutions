class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL)
            return head;
        ListNode *odd, *even, *evenHead, *t;
        odd = head;
        even = head->next;
        evenHead = head->next;
        t = head->next->next;
        int count = 1;

        do {
            if(count%2) {
                odd->next = t;
                odd = odd -> next;
            }
            else {
                even->next = t;
                even = even -> next;
            }
            t = t -> next;
            ++count;
        }while(t!=NULL);
        even->next = NULL;
        odd->next = evenHead;
        return head;
    }
};