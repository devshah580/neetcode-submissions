class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //0, -1, -1, -1
        vector<int> dp(amount + 1, -2);
        dp[0] = 0;        
        return coinHelper(coins, amount, dp);
    }

    int coinHelper(vector<int>& coins, int amount, vector<int>& dp) {
        if(amount < 0 || dp[amount] == -1) {
            return -1;
        }
        if(dp[amount] >= 0) {
            return dp[amount];
        }

        int minCoins = INT_MAX;
        for(int i = 0; i < coins.size(); i++) {
            int neededCoins = coinHelper(coins, amount - coins[i], dp);
            if(neededCoins >= 0) {
                minCoins = min(minCoins, 1 + coinHelper(coins, amount - coins[i], dp));
            }
        }
        if(minCoins == INT_MAX) {
            dp[amount] = -1;
        } else {
            dp[amount] = minCoins;
        }
        
        return dp[amount];
    }
};
