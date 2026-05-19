class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<std::pair<int, int>> to_check;
        vector<int> result(temperatures.size());
        for(int i = 0; i < temperatures.size(); i++) {
            if(to_check.empty() || temperatures[i] <= to_check.top().first) {
                to_check.push({temperatures[i], i});
            } else {
                while(!to_check.empty() && temperatures[i] > to_check.top().first) {
                    result[to_check.top().second] = i - to_check.top().second;
                    to_check.pop();
                }
                to_check.push({temperatures[i], i});
            }
        }
        while(!to_check.empty()) {
            result[to_check.top().second] = 0;
            to_check.pop();
        }
        return result;
    }
};
