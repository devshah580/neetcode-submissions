class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        //-4,-1,-1,0,1,2
        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right) {
                if(nums[left] + nums[right] + nums[i] > 0) {
                    right--;
                } else if(nums[left] + nums[right] + nums[i] < 0) {
                    left++;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    int tempLeft = nums[left];
                    while(left < right && tempLeft == nums[left]) {
                        left++;
                    }

                    int tempRight = nums[right];
                    while(left < right && tempRight == nums[right]) {
                        right--;
                    }
                }
            }
        }
        return result;
    }
};

