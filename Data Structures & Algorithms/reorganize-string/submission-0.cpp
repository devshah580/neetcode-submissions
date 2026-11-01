class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        for(int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }

        priority_queue<pair<int, char>> heap;

        for(int i = 0; i < freq.size(); i++) {
            if(freq[i] == 0) {
                continue;
            }
            heap.push({freq[i], 'a' + i});
        }

        string result = "";
        pair<int, char> prev = {-1, 'a'};
        while(!heap.empty()) {
            auto currElem = heap.top();
            if(result.size() >= 1 && currElem.second == result[result.size() - 1]) {
                break;
            }

            heap.pop();
            result += currElem.second;
            currElem.first--;
            if(prev.first > 0) {
                heap.push(prev);
            }
            prev = currElem;
        }
        if(heap.empty() && prev.first == 0) {
            return result;
        } else {
            return "";
        }
    }
};