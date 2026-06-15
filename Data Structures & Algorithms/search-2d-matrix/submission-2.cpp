class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int minRow = 0;
        int maxRow = matrix.size() - 1;
        int resultRow = -1;
        while(minRow <= maxRow) {
            int currRow = minRow + (maxRow - minRow) / 2;
            if(target == matrix[currRow][0]) {
                return true;
            } else if(matrix[currRow][0] > target) {
                maxRow = currRow - 1;
            } else {
                resultRow = max(resultRow, currRow);
                minRow = currRow + 1;
            }
        }

        if(resultRow == -1) {
            return false;
        }

        int minCol = 0;
        int maxCol = matrix[resultRow].size() - 1;
        while(minCol <= maxCol) {
            int currCol = minCol + (maxCol - minCol) / 2;
            if(target == matrix[resultRow][currCol]) {
                return true;
            } else if(target < matrix[resultRow][currCol]) {
                maxCol = currCol - 1;
            } else {
                minCol = currCol + 1;
            }
        }
        return false;
    }
};
