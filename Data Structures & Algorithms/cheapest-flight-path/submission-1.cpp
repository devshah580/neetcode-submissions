class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> flightMap;
        for(int i = 0; i < flights.size(); i++) {
            flightMap[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        vector<int> airports(n, INT_MAX);
        airports[src] = 0;
        priority_queue<tuple<int, int, int>> to_check;
        to_check.push({0, 0, src});
        while(!to_check.empty()) {
            int currPrice = get<0>(to_check.top());
            int currK = get<1>(to_check.top());
            int currSource = get<2>(to_check.top());
            to_check.pop();
            for(int i = 0; i < flightMap[currSource].size(); i++) {
                if(airports[flightMap[currSource][i].first] > currPrice + flightMap[currSource][i].second) {
                    airports[flightMap[currSource][i].first] = currPrice + flightMap[currSource][i].second;
                    if(currK < k) {
                        to_check.push({airports[flightMap[currSource][i].first], currK + 1, flightMap[currSource][i].first});
                    }
                }
            }
        }
        if(airports[dst] == INT_MAX) {
            return -1;
        }
        return airports[dst];
    }
};
