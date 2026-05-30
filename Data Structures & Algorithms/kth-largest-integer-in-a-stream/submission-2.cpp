class KthLargest {
public:
    int k_ = -1;
    priority_queue<int, std::vector<int>, std::greater<int>> heap;

    KthLargest(int k, vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            heap.push(nums[i]);
            if(heap.size() > k) {
                heap.pop();
            }
        }
        k_ = k;
    }
    
    int add(int val) {
        heap.push(val);
        if(heap.size() > k_) {
            heap.pop();
        }
        return heap.top();
    }
};
