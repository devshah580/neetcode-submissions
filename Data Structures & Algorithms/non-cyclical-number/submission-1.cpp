class Solution {
public:
    bool isHappy(int n) {
        int curr = 0;
        int i = 0;
        while(i < 1000) {
            curr += (n % 10) * (n % 10);
            n = n / 10;
            cout << curr << "    " << n << endl;
            if(n == 0) {
                if(curr == 1) {
                    return true;
                }
                n = curr;
                curr = 0;
            }
            i++;
        }
        return false;

    }
};
