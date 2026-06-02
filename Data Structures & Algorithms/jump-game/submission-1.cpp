class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index = 0;
        //index = 0
        //maxIndex = 3
        while(index < nums.size()) {
            cout << index << endl;
            int maxJump = index;
            int maxIndex = index;
            for(int i = 1; i <= nums[index]; i++) {
                if(index + i < nums.size() && maxJump < i + index + nums[index + i]) {
                    maxJump = i + index + nums[index + i];
                    maxIndex = index + i;
                }
            }

            if(maxJump >= nums.size() - 1) {
                return true;
            }

            if(maxJump == index) {
                return false;
            }
            index = maxIndex;
        }
        return true;
    }
};
