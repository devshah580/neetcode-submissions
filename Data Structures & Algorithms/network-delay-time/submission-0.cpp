class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> edges(n + 1);
        for(int i = 0; i < times.size(); i++) {
            edges[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        vector<int> fastest_time(n + 1, INT_MAX);
        priority_queue<int> to_check;
        to_check.push(k);
        fastest_time[k] = 0;
        while(!to_check.empty()) {
            int curr = to_check.top();
            to_check.pop();
            for(int i = 0; i < edges[curr].size(); i++) {
                pair<int, int> neighbor = edges[curr][i];
                if(fastest_time[neighbor.first] > fastest_time[curr] + neighbor.second) {
                    to_check.push(neighbor.first);
                    fastest_time[neighbor.first] = fastest_time[curr] + neighbor.second;
                }
            }
        }

        int result = -1;
        for(int i = 1; i < fastest_time.size(); i++) {
            if(fastest_time[i] == INT_MAX) {
                return -1;
            }
            result = max(result, fastest_time[i]);
        }
        return result;
    }
};
