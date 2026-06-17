class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
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
                        if(curr.first > 0 && grid[curr.first - 1][curr.second] == 1) {
                            grid[curr.first - 1][curr.second] = 0;
                            to_check.push({curr.first - 1, curr.second});
                            currArea++;
                        }
                        if(curr.first < grid.size() - 1 && grid[curr.first + 1][curr.second] == 1) {
                            grid[curr.first + 1][curr.second] = 0;
                            to_check.push({curr.first + 1, curr.second});
                            currArea++;
                        }

                        if(curr.second > 0 && grid[curr.first][curr.second - 1] == 1) {
                            grid[curr.first][curr.second - 1] = 0;
                            to_check.push({curr.first, curr.second - 1});
                            currArea++;
                        }
                        if(curr.second < grid[0].size() - 1 && grid[curr.first][curr.second + 1] == 1) {
                            grid[curr.first][curr.second + 1] = 0;
                            to_check.push({curr.first, curr.second + 1});
                            currArea++;
                        }
                    }
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        return maxArea;
    }
};
