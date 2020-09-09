class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> vec;
        ListNode* t = head;
        while(t) {
            vec.push_back(t);
            t = t->next;
        }
        int i,n = vec.size();
        if(n <= 2)
            return;
        for(i = 0; i < n-i-1; ++i) {
            vec[i]->next = vec[n-i-1];
            if(i+1<n)
                vec[n-i-1]->next = vec[i+1];
        }
        vec[i]->next = NULL;
    }
};