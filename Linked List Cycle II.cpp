class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !(head->next))
            return nullptr;
        ListNode *tortoise = head, *rabbit = head;
        do {
            rabbit = rabbit -> next -> next;
            tortoise = tortoise -> next;
            if(rabbit == nullptr || rabbit -> next == nullptr || rabbit -> next -> next == nullptr)
                return nullptr;
        } while(rabbit != tortoise);
        rabbit = head;
        while(rabbit != tortoise) {
            rabbit = rabbit -> next;
            tortoise = tortoise -> next;
        }
        return tortoise;
    }
};