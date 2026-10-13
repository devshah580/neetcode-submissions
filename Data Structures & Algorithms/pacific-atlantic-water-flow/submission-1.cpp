class Solution {
public:
    void bfs(vector<vector<int>>& heights, vector<pair<int, int>>& dirs, int i, int j, vector<vector<int>>& connections) {
        if(connections[i][j] > -1) {
            return;
        }
        connections[i][j] = 1;
        queue<pair<int, int>> to_check;
        to_check.push({i, j});

        while(!to_check.empty()) {
            int x = to_check.front().first;
            int y = to_check.front().second;
            to_check.pop();
            for(const auto& dir : dirs) {
                int new_x = x + dir.first;
                int new_y = y + dir.second;
                if(new_x >= 0 && new_y >= 0 && new_x < heights.size() && new_y < heights[0].size()) {
                    if(connections[new_x][new_y] < 0 && heights[new_x][new_y] >= heights[x][y]) {
                        to_check.push({new_x, new_y});
                        connections[new_x][new_y] = 1;
                    }
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> pacificConnections(heights.size(), vector<int>(heights[0].size(), -1));
        vector<vector<int>> atlanticConnections(heights.size(), vector<int>(heights[0].size(), -1));
        for(int i = 0; i < heights.size(); i++) {
            bfs(heights, dirs, i, 0, pacificConnections);
            bfs(heights, dirs, i, heights[0].size() - 1, atlanticConnections);
        }

        for(int i = 0; i < heights[0].size(); i++) {
            bfs(heights, dirs, 0, i, pacificConnections);
            bfs(heights, dirs, heights.size() - 1, i, atlanticConnections);
        }

        vector<vector<int>> result;
        for(int i = 0; i < heights.size(); i++) {
            for(int j = 0; j < heights[0].size(); j++) {
                if(pacificConnections[i][j] == 1 && atlanticConnections[i][j] == 1) {
                    result.push_back({i, j});
                }
            }
        }
        return result;


    }
};
