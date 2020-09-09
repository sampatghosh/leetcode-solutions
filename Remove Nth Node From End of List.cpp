class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return head;
        vector<ListNode*> vec;
        ListNode* t = head;
        while(t) {
            vec.push_back(t);
            t=t->next;
        }
        n = vec.size()-n;
        if(n==vec.size())
            vec[n-2]->next = NULL;
        else if (n == 0)
            head = head->next;
        else
            vec[n-1]->next = vec[n-1]->next->next;
        return head;
    }
};