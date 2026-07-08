class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == '1') {
                    count++;
                    grid[i][j] = '0';
                    bfs(grid, i, j);
                }
            }
        }
        return count;
    }

    void bfs(vector<vector<char>>& grid, int i, int j) {
        vector<pair<int, int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int, int>> to_check;
        to_check.push({i, j});
        while(!to_check.empty()) {
            int x = to_check.front().first;
            int y = to_check.front().second;
            to_check.pop();
            for(auto dir : dirs) {
                int new_x = x + dir.first;
                int new_y = y + dir.second;
                if(min(new_x, new_y) >= 0 && new_x < grid.size() && 
                new_y < grid[0].size() && grid[new_x][new_y] == '1') {
                    grid[new_x][new_y] = '0';
                    to_check.push({new_x, new_y});
                }
            }
        }
    }
};
