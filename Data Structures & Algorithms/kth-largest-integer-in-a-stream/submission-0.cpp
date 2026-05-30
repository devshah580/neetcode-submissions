class KthLargest {
public:
    int kth_largest = -1;
    priority_queue<int> heap;

    KthLargest(int k, vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            heap.push(nums[i]);
        }
        kth_largest = k;
    }
    
    int add(int val) {
        heap.push(val);
        std::vector<int> temp;
        for(int i = 0; i < kth_largest - 1; i++) {
            temp.push_back(heap.top());
            heap.pop();
        }
        int result = heap.top();
        for(int i = 0; i < kth_largest - 1; i++) {
            heap.push(temp[i]);
        }
        return result;
    }
};
