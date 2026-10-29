class Solution {
public:

    bool isPalindrome(string currString) {
        int left = 0;
        int right = currString.size() - 1;
        while(left < right) {
            if(currString[left] != currString[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    
    void helper(string& s, vector<vector<string>>& result, vector<string>& currVec, int index) {
        if(index >= s.size()) {
            result.push_back(currVec);
            return;
        }

        string currString;
        for(int i = index; i < s.size(); i++) {
            currString += s[i];
            if(isPalindrome(currString)) {
                currVec.push_back(currString);
                helper(s, result, currVec, i + 1);
                currVec.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currVec;
        helper(s, result, currVec, 0);
        return result;
    }
};
