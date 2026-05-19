class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty() || t.size() > s.size()) {
            return "";
        }

        std::unordered_map<char, int> window;
        std::unordered_map<char, int> t_mapping;
        for(int i = 0; i < t.size(); i++) {
            t_mapping[t[i]]++;
        }

        int need = t_mapping.size();
        int have = 0;
        int left = 0;
        int right = 0;
        std::string res;
        while (right < s.size()) {
            window[s[right]]++;
            if(t_mapping.count(s[right]) && window[s[right]] == t_mapping[s[right]]) {
                have++;
            }
            while(have == need) {
                if((right - left + 1) < res.size() || res.empty()) {
                    res = s.substr(left, right - left + 1);
                }
                window[s[left]]--;
                if(t_mapping.count(s[left]) && window[s[left]] < t_mapping[s[left]]) {
                    have--;
                }
                left++;
            }
            right++;
        }
        return res;
    }
};
