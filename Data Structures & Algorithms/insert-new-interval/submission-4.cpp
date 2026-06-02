class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int startIndex = 0;
        while(startIndex < intervals.size() && intervals[startIndex][1] < newInterval[0]) {
            startIndex++;
        }

        int endIndex = 0;
        while(endIndex < intervals.size() && intervals[endIndex][0] <= newInterval[1]) {
            endIndex++;
        }

        intervals.insert(intervals.begin() + startIndex, newInterval);
        for(int i = startIndex + 1; i <= endIndex; i++) {
            intervals[startIndex][0] = min(intervals[startIndex][0], intervals[startIndex + 1][0]);
            intervals[startIndex][1] = max(intervals[startIndex][1], intervals[startIndex + 1][1]);
            intervals.erase(intervals.begin() + startIndex + 1);
        }

        for(int i = startIndex + 1; i <= endIndex; i++) {
            
        }

        return intervals;
    }
};
