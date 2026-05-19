class MinStack {
private:
 std::vector<int> stack;
 std::vector<int> minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push_back(val);
        if(minStack.empty()) {
            minStack.push_back(val);
        }
        else if(val <= minStack[minStack.size() - 1]) {
            minStack.push_back(val);
        }
    }
    
    void pop() {
        if(minStack[minStack.size() - 1] == stack[stack.size() - 1]) {
            minStack.pop_back();
        }
        stack.pop_back();
    }
    
    int top() {
        return stack[stack.size() - 1];
    }
    
    int getMin() {
        if(stack.size() == 0) {
            return 0;
        }
        return minStack[minStack.size() - 1];
    }
};
