class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board, string word, 
    bool& found, vector<vector<bool>>& seen) {
        if(word.size() == 0) {
            found = true;
            return;
        }

        if(i - 1 >= 0 && board[i - 1][j] == word[0] && !seen[i - 1][j]) {
            seen[i - 1][j] = true;
            dfs(i - 1, j, board, word.substr(1), found, seen);
            seen[i - 1][j] = false;
        }

        if(j - 1 >= 0 && board[i][j - 1] == word[0] && !seen[i][j - 1]) {
            seen[i][j - 1] = true;
            dfs(i, j - 1, board, word.substr(1), found, seen);
            seen[i][j - 1] = false;
        }

        if(i + 1 < board.size() && board[i + 1][j] == word[0] && !seen[i + 1][j]) {
            seen[i + 1][j] = true;
            dfs(i + 1, j, board, word.substr(1), found, seen);
            seen[i + 1][j] = false;
        }

        if(j + 1 < board[i].size() && board[i][j + 1] == word[0] && !seen[i][j + 1]) {
            seen[i][j + 1] = true;
            dfs(i, j + 1, board, word.substr(1), found, seen);
            seen[i][j + 1] = false;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        bool found = false;
        vector<vector<bool>> seen(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == word[0]) {
                    seen[i][j] = true;
                    dfs(i, j, board, word.substr(1), found, seen);
                    seen[i][j] = false;
                }
            }
        }
        return found;
    }
};
