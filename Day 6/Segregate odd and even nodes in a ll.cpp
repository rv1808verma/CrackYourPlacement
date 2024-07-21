// https://www.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1

    Node* divide(int N, Node *head){
        // code here
    Node *oddHead = new Node(-1), *oddTail = oddHead;
    Node *evenHead = new Node(-1), *evenTail = evenHead;
    Node *curr = head, *temp;
    while (curr){
        temp = curr;
        curr = curr->next;
        temp->next = nullptr;

        if (temp->data & 1) {
            oddTail->next = temp;
            oddTail = temp;
        }
        else {
            evenTail->next = temp;
            evenTail = temp;
        }
    }
    evenTail->next = oddHead->next; 
    return evenHead->next;
    }
