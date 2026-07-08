class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSoFar = INT_MAX;
        int maxProf = 0;
        for(int i = 0; i < prices.size(); i++) {
            minSoFar = min(minSoFar, prices[i]);
            maxProf = max(maxProf, prices[i] - minSoFar);
        }
        return maxProf;
    }
};
