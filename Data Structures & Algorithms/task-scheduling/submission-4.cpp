class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freqs;
        for(int i = 0; i < tasks.size(); i++) {
            freqs[tasks[i]]++;
        }

        priority_queue<pair<int, char>> heap;
        for(auto elem : freqs) {
            heap.push({elem.second, elem.first});
        }

        unordered_map<char, int> last_seen;
        int counter = 0;
        while(heap.size() > 0) {
            vector<pair<int, char>> temp;
            bool foundMatch = false;
            while (!foundMatch && heap.size() > 0) {
                pair<int, char> curr = heap.top();
                heap.pop();
                if (last_seen.count(curr.second) && counter - last_seen[curr.second] <= n) {
                    temp.push_back(curr);
                } else {
                    if (curr.first > 1) {
                        temp.push_back({curr.first - 1, curr.second});
                    }
                    last_seen[curr.second] = counter;
                    foundMatch = true;
                }
            }

            for (int i = 0; i < temp.size(); i++) {
                heap.push(temp[i]);
            }

            counter++;
        }
        return counter;
    }
};





//A -> Idle -> Idle -> Idle -> A -> B -> C -> Idle -> A