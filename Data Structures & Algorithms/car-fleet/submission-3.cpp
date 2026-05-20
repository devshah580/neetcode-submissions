class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<std::pair<int, int>> cars(position.size());
        for(int i = 0; i < position.size(); i++) {
            cars[i] = {position[i], speed[i]};
        }

        std::sort(cars.begin(), cars.end());

        for(int i = 0; i < cars.size(); i++) {
            cout << cars[i].first << "  " << cars[i].second << std::endl;
        }
        int count = 0;
        double slowestTime = 0;
        for(int i = cars.size() - 1; i >= 0; i--) {
            if(((double)(target - cars[i].first) / cars[i].second) > slowestTime) {
                slowestTime = (double)(target - cars[i].first) / cars[i].second;
                count++;
            }
        }
        return count;
    }
};
