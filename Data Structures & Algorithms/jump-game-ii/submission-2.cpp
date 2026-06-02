class Solution {
public:
    int jump(vector<int>& nums) {
        int index = 0;
        int counter = 0;
        while(index + 1 < nums.size()) {
            counter++;
            cout << index << endl;
            if(index + nums[index] + 1 >= nums.size()) {
                break;
            }
            int maxJump = index;
            int maxIndex = index;
            for(int i = 1; i <= nums[index]; i++) {
                if(index + i < nums.size() && maxJump < i + index + nums[index + i]) {
                    maxJump = i + index + nums[index + i];
                    maxIndex = index + i;
                }
            }
            index = maxIndex;
        }
        return counter; 
    }
};
