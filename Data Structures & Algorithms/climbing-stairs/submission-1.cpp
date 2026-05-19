class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> cache(n, 0);
        cache[0] = 1;
        cache[1] = 2;
        return helper(n, cache);
    }
    //1, 2, 3
    int helper(int n, std::vector<int>& cache) {
        if(cache[n - 1] > 0) {
            return cache[n - 1];
        }

        int count = helper (n - 1, cache) + helper (n - 2, cache);
        cache[n-1] = count;
        return count;
    }
};
