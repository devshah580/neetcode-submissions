class NumMatrix {
public:
    vector<vector<int>> prefixes;
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++) {
            prefixes.push_back({matrix[i][0]});
            for(int j = 1; j < matrix[i].size(); j++) {
                prefixes[i].push_back(prefixes[i][j - 1] + matrix[i][j]);
            }
        }

        for(int i = 0; i < matrix[0].size(); i++) {
            for(int j = 1; j < matrix.size(); j++) {
                prefixes[j][i] += prefixes[j - 1][i];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 > 0 && col1 > 0) {
            return prefixes[row2][col2] - prefixes[row1 - 1][col2] - prefixes[row2][col1 - 1] + prefixes[row1 - 1][col1 - 1];
        } else if(row1 > 0) {
            return prefixes[row2][col2] - prefixes[row1 - 1][col2];
        } else if(col1 > 0) {
            return prefixes[row2][col2] - prefixes[row2][col1 - 1];
        } else {
            return prefixes[row2][col2];
        }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */