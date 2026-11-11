class Solution {
public:
    void helper(int n, vector<int>& perfectSquares, int currSum, int& minSum, vector<int>& dp) {
        if(n <= 0) {
            if(n == 0) {
                minSum = min(currSum, minSum);
            }
            return;
        }

        if(dp[n] != -1) {
            return;
        }
        for(int i = perfectSquares.size() - 1; i >= 0; i--) {
            if(n - perfectSquares[i] >= 0) {
                n -= perfectSquares[i];
                helper(n, perfectSquares, currSum + 1, minSum, dp);
                n += perfectSquares[i];
            }
        }
        dp[n] = minSum;
    }
    int numSquares(int n) {
        vector<int> perfectSquares;
        int i = 1;
        while(i * 1 <= n) {
            perfectSquares.push_back(i * i);
            i++;
        }
        vector<int> dp(n + 1, -1);
        int minSum = INT_MAX;
        helper(n, perfectSquares, 0, minSum, dp);
        return minSum;
    }
};