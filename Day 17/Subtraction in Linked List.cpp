// https://www.geeksforgeeks.org/problems/subtraction-in-linked-list/1

private:
    int len(Node* node) {
        Node* curr{node};
        int l{0};
        while(curr){
            l++;
            curr = curr->next;
        }
        return l;
    }
    
    Node* stripLeadingZeroes(Node* head)
    {
        while(head && head->next && head->data == 0)
        {
            Node* trash{head};
            head = head->next;
            delete trash; 
        }
        return head;
    }
    
    Node* reverse(Node* node) {
        if(!node || !node->next) return node;
        
        Node* prev{nullptr};
        Node* curr{node};
        Node* next{node->next};
        
        while(curr)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            if(next) next = next->next;
        }
        
        return prev;
    }

public:
    Node* subLinkedList(Node* head1, Node* head2) {
        head1 = stripLeadingZeroes(head1);
        head2 = stripLeadingZeroes(head2);

        
        int l1{len(head1)};
        int l2{len(head2)};

        if(l2 > l1) swap(head1, head2);
        if(l1 == l2)
        {
            Node* c1{head1};
            Node* c2{head2};
            while(c1 && c2)
            {
                if(c1->data > c2->data) break;
                if(c1->data < c2->data){
                    std::swap(head1, head2);
                    break;
                }
                c1 = c1->next;
                c2 = c2->next;
            }
        }

        int borrow{0};
        head1 = reverse(head1);
        head2 = reverse(head2);
        
        Node* curr1{head1};
        Node* curr2{head2};
        
        while(curr1 && curr2)
        {
            int a{curr1->data};
            int b{curr2->data};
        
            if((a + borrow) < b) {
                curr1->data = a + 10 + borrow  - b;
                if(!borrow) borrow = -1;
            } else {
                curr1->data = a + borrow - b;
                borrow = 0;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        while(borrow && curr1)
        {
            int a{curr1->data};
            if((borrow + a) < 0)
            {
                a += 10 + borrow;
            } else {
                a += borrow;
                borrow = 0;
            }
            
            curr1->data = a;
            
            curr1 = curr1->next;
        }
        return stripLeadingZeroes(reverse(head1));
    }
