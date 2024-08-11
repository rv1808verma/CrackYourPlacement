// https://leetcode.com/problems/implement-queue-using-stacks/description/

  stack < int > input, output;
    MyQueue() {
    }
    
    void push(int x) {
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
        input.push(x);
        while (!output.empty()) {
            input.push(output.top());
            output.pop();
        }
    }
    
    int pop() {
        int val = input.top();
        input.pop();
        return val;
    }
    
    int peek() {
        return input.top();
    }
    
    bool empty() {
        return input.empty(); 
    }
