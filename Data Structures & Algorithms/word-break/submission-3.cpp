class Solution {
public:
    bool helper(string s, unordered_set<string>& words, int index, vector<int>& dp) {
        if(index == s.size()) {
            return true;
        }

        if(dp[index] != -1) {
            return dp[index];
        }

        bool found = false;
        string currString = "";
        for(int i = index; i < s.size(); i++) {
            currString += s[i];
            if(words.count(currString) && helper(s, words, i + 1, dp)) {
                found = true;
                break;
            }
        }

        dp[index] = found;
        return found;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        vector<int> dp(s.size(), -1);
        for(auto& elem : wordDict) {
            words.insert(elem);
        }
        return helper(s, words, 0, dp);
    }
};
