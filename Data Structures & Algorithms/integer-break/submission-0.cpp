class Solution {
public:
    int helper(int n, vector<int>& dp) {
        if(n <= 1) {
            return 1;
        }

        if(dp[n] != INT_MAX) {
            return dp[n];
        }

        int result = INT_MIN;
        for(int i = 1; i < n; i++) {
            result = max(result, i * (n - i));
            result = max(result, i * helper(n - i, dp));
        }

        dp[n] = result;
        return result;
    }
    int integerBreak(int n) {
        vector<int> dp(n + 1, INT_MAX);
        return helper(n, dp);
    }
};