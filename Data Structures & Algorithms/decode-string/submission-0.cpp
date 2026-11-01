class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, string>> multipled_string;
        string result = "";
        for(int i = 0; i < s.size(); i++) {
            if(isdigit(s[i])) {
                int currNum = 0;
                while(isdigit(s[i])) {
                    currNum = currNum * 10 + (s[i] - '0');
                    i++;
                }
                multipled_string.push({currNum, ""});
            } else if(s[i] == ']') {
                string temp = "";
                for(int i = 0; i < multipled_string.top().first; i++) {
                    temp += multipled_string.top().second;
                }
                multipled_string.pop();
                if(!multipled_string.empty()) {
                    multipled_string.top().second += temp;
                } else {
                    result += temp;
                }
            } else {
                if(multipled_string.empty()) {
                    result += s[i];
                } else {
                    multipled_string.top().second += s[i];
                }
            }
        }
        return result;
    }
};