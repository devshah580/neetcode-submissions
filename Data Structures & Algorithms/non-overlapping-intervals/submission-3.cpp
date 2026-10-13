class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> nonLappingIntervals;
        int result = 0;
        int prev = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] >= prev) {
                prev = intervals[i][1];
            } else {
                result++;
                prev = min(intervals[i][1], prev);
            }
        }
        return result;
    }
};
