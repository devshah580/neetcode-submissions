class Solution {
public:
    void helper(string& digits, string& currString, vector<string>& numtoChar, vector<string>& result) {
        if(currString.size() >= digits.size()) {
            if(currString.size() != 0) {
                result.push_back(currString);
            }
            return;
        }

        for(int i = 0; i < numtoChar[digits[currString.size()] - '0'].size(); i++) {
            currString += numtoChar[digits[currString.size()] - '0'][i];
            helper(digits, currString, numtoChar, result);
            currString.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> numtoChar = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        string currString = "";
        helper(digits, currString, numtoChar, result);
        return result;
    }
};
