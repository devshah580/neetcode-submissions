class Solution {
public:
    void helper(int n, vector<int>& perfectSquares, int currSum, int& minSum, vector<int>& dp) {
        if(n <= 0) {
            if(n == 0) {
                minSum = min(currSum, minSum);
            }
            return;
        }

        if(dp[n] != INT_MAX) {
            return;
        }
        cout << n << endl;
        for(int i = perfectSquares.size() - 1; i >= 0; i--) {
            n -= perfectSquares[i];
            helper(n, perfectSquares, currSum + 1, minSum, dp);
            n += perfectSquares[i];
            dp[n] = min(dp[n], n - perfectSquares[i]);
        }
    }
    int numSquares(int n) {
        vector<int> perfectSquares;
        int i = 1;
        while(i * 1 <= n) {
            perfectSquares.push_back(i * i);
            i++;
        }

        vector<int> dp(n + 1, INT_MAX);
        int minSum = INT_MAX;
        helper(n, perfectSquares, 0, minSum, dp);
        return minSum;
    }
};