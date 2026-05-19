class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) {
            return "";
        }
        string result = strs[0];
        for(int i = 1; i < strs.size(); i++) {
            for(int j = 0; j < strs[i].size() && result.size(); j++) {
                if(strs[i][j] != result[j]) {
                    result = result.substr(0, j);
                    break;
                }
            }
            if(strs[i].size() < result.size()) {
                result = strs[i];
            }
        }
        return result;
    }
};