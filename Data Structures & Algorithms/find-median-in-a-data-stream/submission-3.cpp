class MedianFinder {
public:
    std::vector<int> nums;

    MedianFinder() {
    }
    
    void addNum(int num) {
        int index = 0;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            int middle = left + (right - left) / 2;
            if(nums[middle] > num) {
                right = middle - 1;
            } else {
                index = middle + 1;
                left = middle + 1;
            }
        }

        nums.insert(nums.begin() + index, num);
    }
    
    double findMedian() {
        if(nums.size() % 2 == 1) {
            return nums[nums.size() / 2];
        } else {
            return (nums[nums.size() / 2] + nums[(nums.size() / 2 - 1)]) / 2.0;
        }
    }
};
