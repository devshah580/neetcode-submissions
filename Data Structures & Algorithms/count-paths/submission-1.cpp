class Solution {
public:
    int helper(int currM, int currN, vector<vector<int>>& dp) {
        if(currM >= dp.size() || currN >= dp[0].size()) {
            return 0;
        }

        if(dp[currM][currN] != -1) {
            return dp[currM][currN];
        }

        int result = helper(currM + 1, currN, dp);
        result += helper(currM, currN + 1, dp);
        dp[currM][currN] = result;
        return result;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[dp.size() - 1][dp[0].size() - 1] = 1;
        return helper(0, 0, dp);
    }
};
