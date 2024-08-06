// https://www.geeksforgeeks.org/problems/preorder-to-postorder4423/1

    Node* solve(int arr[], int min, int max, int& i,int size){
        if( i >= size ) return NULL;
        if(arr[i] > max || arr[i] < min) return NULL;
        Node* root = newNode(arr[i++]);
        root->left = solve(arr, min, root->data, i,size);
        root->right = solve(arr, root->data, max, i,size);
        return root;
    }

    Node* Bst(int pre[], int size) {
        // code here
        int i = 0, min = INT_MIN, max = INT_MAX;
        Node* root = solve(pre,min,max,i,size);
        return root;
    }
