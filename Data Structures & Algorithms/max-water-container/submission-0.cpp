class Solution {
public:
    int maxArea(vector<int>& heights) {
        int front = 0;
        int end = heights.size() - 1;
        int maxArea = 0;
        while(front < end) {
            int area = (end - front) * min(heights[front], heights[end]);
            maxArea = max(area, maxArea);
            if(heights[front] < heights[end]) {
                front++;
            } else {
                end--;
            }
        }
        return maxArea;
    }
};
