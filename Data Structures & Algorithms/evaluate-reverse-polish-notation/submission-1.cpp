class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> seen;
        int result = 0;

        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+") {
                int temp = seen.top();
                seen.pop();
                temp += seen.top();
                seen.pop();
                seen.push(temp);
            }

            else if(tokens[i] == "-") {
                int temp = seen.top();
                seen.pop();
                temp = seen.top() - temp;
                seen.pop();
                seen.push(temp);
            }

            else if(tokens[i] == "*") {
                int temp = seen.top();
                seen.pop();
                temp *= seen.top();
                seen.pop();
                seen.push(temp);
            }

            else if(tokens[i] == "/") {
                int temp = seen.top();
                seen.pop();
                temp = seen.top() / temp;
                seen.pop();
                seen.push(temp);
            } else {
                seen.push(std::stoi(tokens[i]));
            }
        }

        return seen.top();
    }
};
