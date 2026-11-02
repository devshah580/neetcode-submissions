class NumMatrix {
public:
    vector<vector<int>> prefixes;
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++) {
            prefixes.push_back({});
            int currSum = 0;
            for(int j = 0; j < matrix[i].size(); j++) {
                currSum += matrix[i][j];
                prefixes[i].push_back(currSum);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int result = 0;
        for(int i = row1; i <= row2; i++) {
            if(col1 > 0) {
                result += prefixes[i][col2] - prefixes[i][col1 - 1];
            } else {
                result += prefixes[i][col2];
            }
        }
        return result;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */