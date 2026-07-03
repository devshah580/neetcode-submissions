class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);
        for(int i = 0; i <= n; i++) {
            int currNum = i;
            while(currNum != 0) {
                currNum = currNum & (currNum - 1);
                result[i]++;
            }
        }
        return result;
    }
};
