class Solution {
public:
    Node* flat(Node* t) {
        Node* temp = t;
        Node* prev;
        while(temp) {
            if(temp->next==NULL)
                prev = temp;
            if(temp->child) {
                Node *t1 = flat(temp->child);
                t1->next = temp->next;
                if(temp->next)
                    temp->next->prev = t1;
                temp->child->prev = temp;
                temp->next = temp->child;
                temp->child = NULL;

            }
            temp = temp -> next;
        }
        return prev;
    }
    void calling(Node* head) {
        Node* t = flat(head);
    }
    Node* flatten(Node* head) {
        if(!head)
            return head;
        calling(head);
        return head;
    }
};