class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> available_times;
        for(int i = 0; i < tasks.size(); i++) {
            available_times.push({tasks[i][0], tasks[i][1], i});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> to_process;
        int curr_time = available_times.top()[0];
        vector<int> result;
        while(!available_times.empty() || !to_process.empty()) {
            if(!available_times.empty() && curr_time < available_times.top()[0]) {
                curr_time = available_times.top()[0];
            }

            while(!available_times.empty() && available_times.top()[0] <= curr_time) {
                to_process.push({
                    available_times.top()[1],
                    available_times.top()[2]
                });
                available_times.pop();
            }

            if(!to_process.empty()) {
                result.push_back(to_process.top()[1]);
                curr_time += to_process.top()[0];
                to_process.pop();
            }
        }
        return result;
    }
};