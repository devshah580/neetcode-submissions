class Solution {
public:
    int climbStairs(int n) {
        std::unordered_map<int, int> dp;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        return helper(n, dp);
    }

    int helper(int n, unordered_map<int, int>& dp) {
        if(dp.count(n)) {
            return dp[n];
        }
        int count = helper(n - 1, dp) + helper(n - 2, dp);
        dp[n] = count;
        return count;
    }
};
