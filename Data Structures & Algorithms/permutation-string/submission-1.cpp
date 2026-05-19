class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) {
            return false;
        }
        std::vector<int> s1Count(26);
        std::vector<int> s2Count(26);

        for(int i = 0; i < s1.size(); i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }
        for(int i = s1.size() - 1; i < s2.size(); i++) {
            if(s1Count == s2Count) {
                return true;
            } else {
                if(i != s2.size() - 1) {
                    s2Count[s2[i + 1] - 'a']++;
                }
                s2Count[s2[i - s1.size() + 1] - 'a']--;
            }
        }
        return false;
    }
};
