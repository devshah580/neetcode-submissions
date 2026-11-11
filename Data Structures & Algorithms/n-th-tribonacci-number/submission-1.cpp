class Solution {
public:
    int helper(int n, vector<int>& dp) {
        if(n < 0 || n >= dp.size()) {
            return 0;
        }

        if(dp[n] != -1) {
            return dp[n];
        }

        dp[n] = 0;
        dp[n] += helper(n - 1, dp);
        dp[n] += helper(n - 2, dp);
        dp[n] += helper(n - 3, dp);
        return dp[n];
    }
    int tribonacci(int n) {
        if(n == 0) {
            return 0;
        }
        if(n == 1 || n == 2) {
            return 1;
        }
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        return helper(n, dp);
    }
};