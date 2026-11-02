class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = INT_MIN;
        int right = 0;
        int result = INT_MAX;
        for(int i = 0; i < weights.size(); i++) {
            right += weights[i];
            left = max(left, weights[i]);
        }

        while(left <= right) {
            int mid = left + (right - left) / 2;

            int currDays = 1;
            int currWeight = 0;
            for(int i = 0; i < weights.size(); i++) {
                if(currWeight + weights[i] <= mid) {
                    currWeight += weights[i];
                } else {
                    currDays++;
                    currWeight = weights[i];
                }
            }

            if(days >= currDays) {
                result = min(result, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};