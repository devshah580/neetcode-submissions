class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> nextLargestNum;
        vector<int> result;
        nextLargestNum.push_back(nums[0]);
        for(int i = 1; i < k; i++) {
            while(!nextLargestNum.empty() && nextLargestNum.back() < nums[i]) {
                nextLargestNum.pop_back();
            }
            nextLargestNum.push_back(nums[i]);
        }
        
        result.push_back(nextLargestNum.front());
        for(int i = k; i < nums.size(); i++) {
            while(!nextLargestNum.empty() && nextLargestNum.back() < nums[i]) {
                nextLargestNum.pop_back();
            }
            nextLargestNum.push_back(nums[i]);
            if(nums[i - k] == nextLargestNum.front()) {
                nextLargestNum.pop_front();
            }
            result.push_back(nextLargestNum.front());
        }
        return result;
        
    }
};
