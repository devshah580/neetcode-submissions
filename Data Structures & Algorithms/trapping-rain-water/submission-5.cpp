class Solution {
public:
    int trap(vector<int>& height) {
        int curr = 0;
        int water = 0;
        first: while (curr != height.size()) {
            int i = curr + 1;
            int localWater = 0;
            while (height[i] < height[curr] && i != height.size()) {
                localWater += height[curr] - height[i];
                i++;
                if (i >= height.size()) {
                    height[curr]--;                    
                    goto first;
                }
            }
            water += localWater;
            curr = i;
        }    
        return water;  
    }
};