class Solution {
public:
    bool isValid(string s) {
        std::stack<char> seen;
        std::unordered_map<char, char> closeToOpen = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for(int i = 0; i < s.size(); i++) {
            if(closeToOpen.count(s[i])) {
                if(!seen.empty() && seen.top() == closeToOpen[s[i]]) {
                    seen.pop();
                } else {
                    return false;
                }
            } else {
                seen.push(s[i]);
            }
        }
        return seen.empty();
    }
};
