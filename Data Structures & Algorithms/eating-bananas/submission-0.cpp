class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minK = 1;
        int maxK = -1;
        for(int i = 0; i < piles.size(); i++) {
            maxK = max(maxK, piles[i]);
        }

        int result = INT_MAX;
        while(minK <= maxK) {
            int currentK = minK + (maxK - minK) / 2;
            int currentNeed = 0;
            for(int i = 0; i < piles.size(); i++) {
                currentNeed += (piles[i] + currentK - 1) / currentK;
            }

            if(currentNeed <= h) {
                result = min(result, currentK);
                maxK = currentK - 1;
            } else {
                minK = currentK + 1;
            }
        }
        return result;
    }
};
