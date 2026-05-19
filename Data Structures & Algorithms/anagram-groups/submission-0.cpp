class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> counts;
        for(int i = 0; i < strs.size(); i++) {
            vector<int> letters(26, 0);
            string word = strs[i];
            for(int j = 0; j < word.size(); j++) {
                letters[word[j] - 'a']++;
            }
            counts[letters].push_back(word);
        }
        vector<vector<string>> result;
        for(const auto& [key, value] : counts) {
            result.push_back(value);
        }
        return result;
    }
};
