class MinStack {
private:
 std::vector<int> stack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push_back(val);
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack[stack.size() - 1];
    }
    
    int getMin() {
        if(stack.size() == 0) {
            return 0;
        }
        int min = stack[0];
        for(int i = 0; i < stack.size(); i++) {
            min = std::min(min, stack[i]);
        }
        return min;
    }
};
