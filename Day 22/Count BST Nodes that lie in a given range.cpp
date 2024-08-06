// https://www.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1

    int getCount(Node *root, int l, int h)
    {
        queue<Node*>q;
      
        if(root==NULL) return 0;
      
        q.push(root);
        int cnt=0;
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
          
            if(temp->data>=l && temp->data<=h) cnt++;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        return cnt;
    }
