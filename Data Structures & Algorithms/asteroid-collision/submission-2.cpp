class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<pair<int, int>> leftAsteroids;
        stack<pair<int, int>> rightAsteroids;
        for(int i = 0; i < asteroids.size(); i++) {
            if(asteroids[i] > 0) {
                rightAsteroids.push({asteroids[i], i});
            } else {
                leftAsteroids.push({abs(asteroids[i]), i});
            }

            while(!leftAsteroids.empty() && !rightAsteroids.empty()) {
                if(leftAsteroids.top().second < rightAsteroids.top().second) {
                    break;
                }

                if(leftAsteroids.top().first > rightAsteroids.top().first) {
                    rightAsteroids.pop();
                } else if(leftAsteroids.top().first < rightAsteroids.top().first) {
                    leftAsteroids.pop();
                } else {
                    rightAsteroids.pop();
                    leftAsteroids.pop();
                }
            }
        }

        vector<int> result;
                while(!rightAsteroids.empty()) {
            result.push_back(rightAsteroids.top().first);
            rightAsteroids.pop();
        }

        while(!leftAsteroids.empty()) {
            result.push_back(-1 * leftAsteroids.top().first);
            leftAsteroids.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};