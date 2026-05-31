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
            auto curr = heap.top();
            vector<pair<int, char>> temp;
            while(heap.size() > 0 && last_seen.count(curr.second) && counter - last_seen[curr.second] <= n) {
                temp.push_back(heap.top());
                heap.pop();
                if(heap.size() > 0) {
                    curr = heap.top();
                }
            }

            if(heap.size() > 0) {
                last_seen[curr.second] = counter;
                heap.pop();
                if(curr.first != 1) {
                    heap.push({curr.first - 1, curr.second});
                }
            }

            for(int i = 0; i < temp.size(); i++) {
                heap.push(temp[i]);
            }

            counter++;
        }
        return counter;
    }
};





//A -> Idle -> Idle -> Idle -> A -> B -> C -> Idle -> A