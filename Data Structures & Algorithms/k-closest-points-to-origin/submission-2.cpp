class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap;
        for(int i = 0; i < points.size(); i++) {
            int temp = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            heap.push({temp, points[i][0], points[i][1]});
        }

        vector<vector<int>> result(k);
        for(int i = 0; i < result.size(); i++) {
            result[i] = {get<1>(heap.top()), get<2>(heap.top())};
            heap.pop();
        }
        return result;
    }
};
