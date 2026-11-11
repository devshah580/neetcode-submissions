class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() <= 1) {
            return 1;
        }
        int result = 0;
        int curr = 1;
        bool direction = arr[0] < arr[1];
        for(int i = 0; i < arr.size() - 1; i++) {
            if((i % 2 == 0 && arr[i] < arr[i+1]) || (i % 2 != 0 && arr[i] > arr[i+1])) {
                if(direction == true) {
                    curr++;
                } else {
                    curr = 2;
                    direction = true;
                }
            }
            
            if((i % 2 == 0 && arr[i] > arr[i+1]) || (i % 2 != 0 && arr[i] < arr[i+1])) {
                if(direction == false) {
                    curr++;
                } else {
                    curr = 2;
                    direction = false;
                }
            }
            result = max(curr, result);
        }
        return result;
    }
};