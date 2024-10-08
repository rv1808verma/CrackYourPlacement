// https://www.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1

    int *arr;
    int size;
    int top1, top2;
    public:
    
    twoStacks(int n=100)
    {
        size = n; 
        arr = new int[n]; 
        top1 = -1; 
        top2 = size;
    }
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
        if(top2 - top1 > 1){
            top1++;
            arr[top1] = x;
        }
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
            if(top2 - top1 > 1){
            top2--;
            arr[top2] = x;
        }   
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(top1 >= 0){
            int ans = arr[top1];
            top1--;
            return ans;
        }
        return -1;        
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
        if(top2 < size){
            int ans = arr[top2];
            top2++;
            return ans;
        }
        return -1;    
    }
