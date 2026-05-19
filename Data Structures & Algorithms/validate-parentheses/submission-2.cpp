class Solution {
public:
    bool isValid(string s) {
        std::stack<char> seen;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '{' || s[i] == '[' || s[i] == '(') {
                seen.push(s[i]);
            } else {
                if(seen.empty()) {
                    return false;
                }
                else if(s[i] == '}' && seen.top() != '{') {
                    return false;
                } else if(s[i] == ']' && seen.top() != '[') {
                    return false;
                } else if (s[i] == ')' && seen.top() != '(') {
                    return false;
                } else {
                    seen.pop();
                }
            }
        }
        if(!seen.empty()) {
            return false;
        }
        return true;
    }
};
