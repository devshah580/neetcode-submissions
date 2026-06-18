class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 0) {
                    queue<tuple<int, int, int>> to_check;
                    to_check.push({i, j, 0});
                    while(!to_check.empty()) {
                        auto curr = to_check.front();
                        to_check.pop();
                        for(auto dir : dirs) {
                            int x = get<0>(curr) + dir.first;
                            int y = get<1>(curr) + dir.second;
                            if(min(x, y) >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] > 0) {
                                if(get<2>(curr) + 1 < grid[x][y]) {
                                    grid[x][y] = get<2>(curr) + 1;
                                    to_check.push({x, y, get<2>(curr) + 1});
                                }
                            }
                        }
                    }
                }
            }
        }
    }
};
