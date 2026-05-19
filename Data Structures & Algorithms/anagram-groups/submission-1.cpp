class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> counts;
        for(int i = 0; i < strs.size(); i++) {
            vector<int> letters(26, 0);
            string word = strs[i];
            for(int j = 0; j < word.size(); j++) {
                letters[word[j] - 'a']++;
            }
            
            string key = to_string(letters[0]);
            for(int j = 1; j < letters.size(); j++) {
                key += ',' + to_string(letters[j]);
            }
            counts[key].push_back(word);
        }
        vector<vector<string>> result;
        for(const auto& [key, value] : counts) {
            result.push_back(value);
        }
        return result;
    }
};
