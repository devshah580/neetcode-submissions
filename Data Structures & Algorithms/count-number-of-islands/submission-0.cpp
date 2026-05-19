class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(!seen[i][j]) {
                    seen[i][j] = true;
                    if(grid[i][j] == '1') {
                        count++;
                        std::deque<std::pair<int, int>> to_check;
                        to_check.push_back({i, j});
                        while(!to_check.empty()) {
                            int x = to_check.front().first;
                            int y = to_check.front().second;
                            seen[x][y] = true;
                            to_check.pop_front();
                            if(x - 1 >= 0 && grid[x - 1][y] == '1' && !seen[x - 1][y]) {
                                to_check.push_back({x - 1, y});
                            }

                            if(y - 1 >= 0 && grid[x][y - 1] == '1' && !seen[x][y - 1]) {
                                to_check.push_back({x, y - 1});
                            }

                            if(x + 1 < grid.size() && grid[x + 1][y] == '1' && !seen[x + 1][y]) {
                                to_check.push_back({x + 1, y});
                            }

                            if(y + 1 < grid[x].size() && grid[x][y + 1] == '1' && !seen[x][y + 1]) {
                                to_check.push_back({x, y + 1});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};
