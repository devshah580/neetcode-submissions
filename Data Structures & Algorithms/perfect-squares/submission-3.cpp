class Solution {
public:
    int helper(int n, vector<int>& perfectSquares, vector<int>& dp) {
        if(n <= 0) {
            return 0;
        }
        

        if(dp[n] != INT_MAX) {
            return dp[n];
        }
        for(int i = perfectSquares.size() - 1; i >= 0; i--) {
            if(n - perfectSquares[i] < 0) {
                continue;
            }
            dp[n] = min(dp[n], 1 + helper(n - perfectSquares[i], perfectSquares, dp));
        }
        return dp[n];
    }
    int numSquares(int n) {
        vector<int> perfectSquares;
        int i = 1;
        while(i * 1 <= n) {
            perfectSquares.push_back(i * i);
            i++;
        }

        vector<int> dp(n + 1, INT_MAX);
        return helper(n, perfectSquares, dp);
    }
};