class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while(x != 0) {
            int digit = x % 10;
            if(result > (INT_MAX / 10 + digit) || result < (INT_MIN / 10 - digit)) {
                return 0;
            }
            result *= 10;
            result += digit;
            x = x / 10;
        }
        return result;
    }
};
