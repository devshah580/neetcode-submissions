class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int maxTime = 0;
        std::deque<std::pair<int,int>> rotted;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 2) {
                    rotted.push_back({i, j});
                }
            }
        }

        if(!rotted.empty()) {
            maxTime--;
        }

        while(!rotted.empty()) {
            int size = rotted.size();
            int count = 0;
            maxTime++;
            while(count < size) {
                count++;
                int x = rotted.front().first;
                int y = rotted.front().second;
                rotted.pop_front();
                if(x - 1 >= 0 && grid[x - 1][y] == 1) {
                    grid[x - 1][y] = 2;
                    rotted.push_back({x - 1, y});
                }

                if(y - 1 >= 0 && grid[x][y - 1] == 1) {
                    grid[x][y - 1] = 2;
                    rotted.push_back({x, y - 1});
                }

                if(x + 1 < grid.size() && grid[x + 1][y] == 1) {
                    grid[x + 1][y] = 2;
                    rotted.push_back({x + 1, y});
                }
                
                if(y + 1 < grid[0].size() && grid[x][y + 1] == 1) {
                    grid[x][y + 1] = 2;
                    rotted.push_back({x, y + 1});
                }
            }
        }
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return maxTime;
    }
};
