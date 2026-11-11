class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool found = false;
        for(int i = digits.size() - 1; i >= 0; i--) {
            if(digits[i] == 9) {
                digits[i] = 0;
            } else {
                found = true;
                digits[i]++;
                break;
            }
        }
        if(!found) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
