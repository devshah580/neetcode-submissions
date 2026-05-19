class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for(int i = 0; i < strs.size(); i++) {
            result += (to_string(strs[i].size()) + "#" + strs[i]);
        }
        std::cout << result << endl;
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        for(int i = 0; i < s.size(); i++) {
            if(isdigit(s[i])) {
                string word;
                string num;
                num.push_back(s[i]);
                i++;
                while(s[i] != '#') {
                    num += s[i];
                    i++;
                }
                int count = i + stoi(num);
                while(i < count) {
                    i++;
                    word += s[i];
                }
                result.push_back(word);
            }
        }
        return result;
    }
};
