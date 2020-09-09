class Solution {
public:
    ListNode* mergeSort(ListNode* root) {
        ListNode* fast = root;
        ListNode* slow = root;
        ListNode* first;
        ListNode* second;
        while(true) {
            if(fast->next == nullptr or fast->next->next == nullptr) {
                second = slow->next;
                break;
            } else {
                slow = slow->next;
                fast = fast->next->next;
            }
        }
        slow->next = nullptr;
        first = root;
        if(first->next != nullptr)
            first = mergeSort(first);
        if(second->next != nullptr)
            second = mergeSort(second);
        return merge(first, second);
    }
    ListNode* merge(ListNode* p, ListNode* q) {
        ListNode dummy(-1);
        ListNode* root = &dummy;
        while(p and q) {
            if(p->val <= q->val) {
                root->next = p;
                root = root->next;
                p = p->next;
                if(p == nullptr) {
                    root->next = q;
                }
            } else {
                root->next = q;
                root = root->next;
                q = q->next;
                if(q == nullptr) {
                    root->next = p;
                }
            }
        }
        return dummy.next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next)
            return head;
        return mergeSort(head);
    }
};