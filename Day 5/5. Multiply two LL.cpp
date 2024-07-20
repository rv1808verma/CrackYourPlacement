// https://www.geeksforgeeks.org/problems/multiply-two-linked-lists/1

    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long mod=1e9+7;
        Node *temp1=first;
        Node* temp2=second;
        
        long long sum1=0, sum2=0;
        while(temp1!=NULL){
            sum1=(sum1*10+temp1->data)%mod;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            sum2=(sum2*10+temp2->data)%mod;
            temp2=temp2->next;
        }
        
        return (sum1*sum2)%mod;
    }
