class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        std::vector<int> s_freq(26, 0);
        std::vector<int> t_freq(26, 0);
        for(int i = 0; i < s.size(); i++) {
            s_freq[s[i] - 'a']++;
            t_freq[t[i] - 'a']++;
        }
        return s_freq == t_freq;
    }
};
