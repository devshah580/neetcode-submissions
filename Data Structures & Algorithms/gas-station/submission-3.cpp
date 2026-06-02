class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum = 0;
        int costSum = 0;
        int index = -1;
        int currSum = 0;
        int maxIndex = -1;
        int maxSum = 0;
        for(int i = 0; i < gas.size(); i++) {
            gasSum += gas[i];
            costSum += cost[i];
            currSum += (gas[i] - cost[i]);
            if(currSum < 0) {
                currSum = 0;
                index = i;
            }
            if(currSum > maxSum) {
                maxIndex = index;
                maxSum = currSum;
            }
        }
        for(int i = 0; i < gas.size(); i++) {
            gasSum += gas[i];
            costSum += cost[i];
            currSum += (gas[i] - cost[i]);
            if(currSum < 0) {
                currSum = 0;
                index = i;
            }
            if(currSum > maxSum) {
                maxIndex = index;
                maxSum = currSum;
            }
        }
        if(gasSum < costSum) {
            return -1;
        } else {
            return maxIndex + 1;
        }
    }
};
