class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](const auto& a, const auto& b) {
            if (a[1] != b[1]) {
                return a[1] < b[1];
            }
            if (a[2] != b[2]) {
                return a[2] > b[2];
            }
            return a[0] > b[0];
        });

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dests;
        int currCount = 0;
        for(int i = 0; i < trips.size(); i++) {
            while(!dests.empty() && trips[i][1] >= dests.top().first) {
                currCount -= dests.top().second;
                dests.pop();
            }
            currCount += trips[i][0];
            dests.push({trips[i][2], trips[i][0]});
            if(currCount > capacity) {
                return false;
            }
        }
        return true;
    }
};