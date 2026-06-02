class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> firstIndex;
        unordered_map<char, int> lastIndex;
        for(int i = 0; i < s.size(); i++) {
            if(!firstIndex.count(s[i])) {
                firstIndex[s[i]] = i;
            }

            if(!lastIndex.count(s[s.size() - i - 1])) {
                lastIndex[s[s.size() - i - 1]] = s.size() - i - 1;
            }
        }

        std::vector<int> result;
        int farthestIndex = -1;
        for(int i = 0; i < s.size(); i++) {
            if(farthestIndex < firstIndex[s[i]]) {
                int distance = lastIndex[s[i]] - firstIndex[s[i]];
                result.push_back(distance + 1);
                farthestIndex = lastIndex[s[i]];
            } else if(farthestIndex < lastIndex[s[i]]) {
                result[result.size() - 1] += lastIndex[s[i]] - farthestIndex;
                farthestIndex = lastIndex[s[i]];
            }
        }
        return result;
    }
};
