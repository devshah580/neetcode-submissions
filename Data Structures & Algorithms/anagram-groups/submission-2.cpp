class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for(int i = 0; i < strs.size(); i++) {
            std::vector<int> char_freq(26, 0);
            for(int j = 0; j < strs[i].size(); j++) {
                char_freq[strs[i][j] - 'a']++;
            }
            
            string freq_string = "";
            for(int j = 0; j < 26; j++) {
                freq_string += char_freq[j];
                freq_string += "|";
            }
            groups[freq_string].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for(auto& elem : groups) {
            result.push_back(elem.second);
        }
        return result;
    }
};
