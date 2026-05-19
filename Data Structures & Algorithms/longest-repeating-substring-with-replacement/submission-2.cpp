class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> counts;
        int highestFreq = 0;
        int result = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++) {
            counts[s[i]]++;
            highestFreq = std::max(highestFreq, counts[s[i]]);

            while ((i - left + 1) - highestFreq > k) {
                counts[s[left]]--;
                left++;
            }

            result = std::max(result, i - left + 1);
        }
        return result;
    }
};
