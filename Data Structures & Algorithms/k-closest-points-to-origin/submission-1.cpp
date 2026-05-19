class Solution {
public:

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;  // min-heap based on second
    }
};

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<pair<int, double>, std::vector<pair<int, double>>, Compare> min_pq;
        for(int i = 0; i < points.size(); i++) {
            double distance = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            min_pq.push({i, distance});
        }
        
        vector<vector<int>> result(k);
        for(int i = 0; i < k; i++) {
            result[i] = points[min_pq.top().first];
            min_pq.pop();
        }

        return result;
    }
};
