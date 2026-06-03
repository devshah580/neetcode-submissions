class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> cache(cost.size() + 1, 0);
        for(int i = 2; i < cache.size(); i++) {
            cache[i] = min(cache[i - 1] + cost[i - 1], cache[i - 2] + cost[i - 2]);
        }
        return cache[cache.size() - 1];
    }
};
