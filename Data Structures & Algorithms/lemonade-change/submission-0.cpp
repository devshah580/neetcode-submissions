class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveCount = 0;
        int tenCount = 0;
        for(int i = 0; i < bills.size(); i++) {
            if(bills[i] == 5) {
                fiveCount++;
            } else if(bills[i] == 10) {
                if(fiveCount == 0) {
                    return false;
                }
                tenCount++;
                fiveCount--;
            } else {
                if(tenCount > 0 && fiveCount > 0) {
                    tenCount--;
                    fiveCount--;
                } else if(fiveCount >= 3) {
                    fiveCount -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};