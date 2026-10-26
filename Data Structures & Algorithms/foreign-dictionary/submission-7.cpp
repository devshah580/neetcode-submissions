class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> ordering;
        unordered_map<char, int> prereqs;
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words[i].size(); j++) {
                prereqs[words[i][j]] = 0;
            }
        }

        for(int i = 0; i < words.size() - 1; i++) {
            int index = 0;
            bool found = false;
            while(index < words[i].size() && index < words[i + 1].size()) {
                if(words[i][index] != words[i + 1][index]) {
                    if(!ordering[words[i][index]].count(words[i + 1][index])) {
                        ordering[words[i][index]].insert(words[i + 1][index]);
                        prereqs[words[i + 1][index]]++;
                    }
                    found = true;
                    break;
                }
                index++;
            }
            if(!found && index == words[i + 1].size() && index != words[i].size()) {
                return "";
            }
        }


        queue<char> to_check;
        for(auto elem : prereqs) {
            if(elem.second == 0) {
                to_check.push(elem.first);
            }
        }

        string result = "";
        while(!to_check.empty()) {
            char curr = to_check.front();
            result += curr;
            to_check.pop();
            for(auto neighbor : ordering[curr]) {
                prereqs[neighbor]--;
                if(prereqs[neighbor] == 0) {
                    to_check.push(neighbor);
                }
            }
        }

        for(auto elem : prereqs) {
            if(elem.second != 0) {
                return "";
            }
        }
        return result;

        
    }
};
