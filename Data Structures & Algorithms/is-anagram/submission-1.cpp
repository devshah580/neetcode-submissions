class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        std::unordered_map<char, std::pair<int, int>> freqs;
        for(int i = 0; i < s.size(); i++) {
            freqs[s[i]].first++;
        }
        for(int i = 0; i < t.size(); i++) {
            freqs[t[i]].second++;
        }
        for(const auto& [key, value] : freqs) {
            if(value.first != value.second) {
                return false;
            }
        }
        return true;
    }
};
