class Solution {
public:
    int helper(int amount, vector<int>& coins, int index, vector<vector<int>>& dp) {
        if(amount < 0 || index >= coins.size()) {
            return 0;
        }

        if(dp[amount][index] != -1) {
            return dp[amount][index];
        }

        if(amount == 0) {
            return 1;
        }

        int result = 0;
        for(int i = index; i < coins.size(); i++) {
            result += helper(amount - coins[i], coins, i, dp);
        }
        dp[amount][index] = result;
        return result;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size(), -1));
        return helper(amount, coins, 0, dp);
    }
};
