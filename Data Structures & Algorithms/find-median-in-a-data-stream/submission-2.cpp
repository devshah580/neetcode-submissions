class MedianFinder {
public:
    std::vector<int> nums;

    MedianFinder() {
    }
    
    void addNum(int num) {
        int index = 0;
        while(index < nums.size() && nums[index] < num) {
            index++;
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
