class Solution {
public:
    void bfs(vector<vector<char>>& board, vector<pair<int, int>>& dirs, int i, int j) {
        vector<pair<int, int>> seen;
        queue<pair<int, int>> to_check;
        bool found = false;
        to_check.push({i, j});
        seen.push_back({i, j});
        board[i][j] = 'Z';
        while(!to_check.empty()) {
            int x = to_check.front().first;
            int y = to_check.front().second;
            to_check.pop();
            for(const auto& dir : dirs) {
                int new_x = x + dir.first;
                int new_y = y + dir.second;
                if(new_x >= 0 && new_y >= 0 && new_x < board.size() && new_y < board[0].size() && board[new_x][new_y] == 'O') {
                    board[new_x][new_y] = 'Z';
                    seen.push_back({new_x, new_y});
                    to_check.push({new_x, new_y});
                    if(new_x == 0 || new_y == 0 || new_x == board.size() -1 || new_y == board[0].size() - 1) {
                        found = true;
                    }
                }
            }
        }

        if(!found) {
            for(int i = 0; i < seen.size(); i++) {
                board[seen[i].first][seen[i].second] = 'X';
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int i = 1; i < board.size() - 1; i++) {
            for(int j = 1; j < board[i].size() - 1; j++) {
                if(board[i][j] == 'O') {
                    bfs(board, dirs, i, j);
                }
            }
        }

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == 'Z') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
