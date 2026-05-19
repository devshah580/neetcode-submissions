class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) {
            set<char> seen;
            set<char> seen_two;
            for(int j = 0; j < board[i].size(); j++) {
                if(seen.count(board[i][j])) {
                    return false; 
                }
                if(board[i][j] != '.') {
                    seen.insert(board[i][j]);
                }
                if(seen_two.count(board[j][i])) {
                    return false; 
                }
                if(board[j][i] != '.') {
                    seen_two.insert(board[j][i]);
                }
            }
        }
        
        for(int grid = 0; grid < 9; grid++) {
            int n = (grid / 3) * 3;
            int m = (grid % 3) * 3;
            set<char> seen;
            for(int i = 0 + n; i < 3 + n; i++) {
                for(int j = 0 + m; j < 3 + m; j++) {
                    if(seen.count(board[i][j])) {
                        return false; 
                        }
                    if(board[i][j] != '.') {
                        seen.insert(board[i][j]);
                    }
                }
            }
        }

        return true;
    }
};
