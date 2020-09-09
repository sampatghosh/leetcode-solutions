class Solution {
public:
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* head=NULL;
        if(!left && !right)
            return head;
        if(!left)
            return right;
        if(!right)
            return left;
        ListNode* t1 = left;
        ListNode* t2 = right;
        ListNode* curr;
        while(t1 && t2) {
            if(t1->val < t2->val) {
                if(head==NULL) {
                    head = new ListNode();
                    head->val = t1->val;
                    curr = head;
                } else {
                    ListNode* temp = new ListNode();
                    temp->val = t1->val;
                    curr->next = temp;
                    curr = curr->next;
                }
                t1=t1->next;
            } else if (t1->val > t2->val) {
                if(head==NULL) {
                    head = new ListNode();
                    head->val = t2->val;
                    curr = head;
                } else {
                    ListNode* temp = new ListNode();
                    temp->val = t2->val;
                    curr->next = temp;
                    curr = curr->next;
                }
                t2=t2->next;
            } else {
                if(head==NULL) {
                    head = new ListNode();
                    head->val = t1->val;
                    curr = head;
                    ListNode* temp = new ListNode();
                    temp->val = t2->val;
                    curr->next = temp;
                    curr = curr->next;
                } else {
                    ListNode* temp1 = new ListNode();
                    temp1->val = t1->val;
                    curr->next = temp1;
                    curr = curr->next;
                    ListNode* temp2 = new ListNode();
                    temp2->val = t2->val;
                    curr->next = temp2;
                    curr = curr->next;
                }
                t1 = t1->next;
                t2 = t2->next;
            }
        }
        while(t1) {
            if(head==NULL) {
                head = new ListNode();
                head->val = t1->val;
                curr = head;
            } else {
                ListNode* temp = new ListNode();
                temp->val = t1->val;
                curr->next = temp;
                curr = curr->next;
            }
            t1=t1->next;
        }
        while(t2) {
            if(head==NULL) {
                head = new ListNode();
                head->val = t2->val;
                curr = head;
            } else {
                ListNode* temp = new ListNode();
                temp->val = t2->val;
                curr->next = temp;
                curr = curr->next;
            }
            t2=t2->next;
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists, int l, int r) {
        if(r-l>=2) {
            int mid = l + ((r-l) / 2);
            ListNode* left = mergeKLists(lists, l, mid);
            ListNode* right = mergeKLists(lists, mid+1, r);
            return merge(left,right);
        } else if(r-l == 1)
            return merge(lists[l],lists[r]);
        else
            return lists[l];
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size())
            return mergeKLists(lists,0,lists.size()-1);
        else
            return NULL;
    }
};