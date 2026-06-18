class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    int currArea = 0;
                    queue<pair<int, int>> to_check;
                    to_check.push({i, j});
                    grid[i][j] = 0;
                    currArea++;
                    while(!to_check.empty()) {
                        auto curr = to_check.front();
                        to_check.pop();
                        for (auto &dir : dirs) {
                            int row = dir.first + curr.first;
                            int col = dir.second + curr.second;
                            if (min(row, col) >= 0 && row < grid.size() && col < grid[0].size() && grid[row][col] == 1) {
                                grid[row][col] = 0;
                                to_check.push({row, col});
                                currArea++;
                            }
                        }
                    }
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        return maxArea;
    }
};
