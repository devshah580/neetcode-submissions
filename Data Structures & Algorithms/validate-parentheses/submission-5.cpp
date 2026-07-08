class Solution {
public:
    bool isValid(string s) {
        stack<char> open_brackets;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                open_brackets.push(s[i]);
            } else if(s[i] == ')' && !open_brackets.empty() && open_brackets.top() == '(') {
                open_brackets.pop();
            } else if(s[i] == '}' && !open_brackets.empty() && open_brackets.top() == '{') {
                open_brackets.pop();
            } else if(s[i] == ']' && !open_brackets.empty() && open_brackets.top() == '[') {
                open_brackets.pop();
            } else {
                return false;
            }
        }
        return open_brackets.empty();
    }
};
