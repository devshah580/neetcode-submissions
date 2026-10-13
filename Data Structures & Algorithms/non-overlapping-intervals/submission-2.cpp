class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> nonLappingIntervals;
        nonLappingIntervals.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] >= nonLappingIntervals[nonLappingIntervals.size() - 1][1]) {
                nonLappingIntervals.push_back(intervals[i]);
            } else {
                nonLappingIntervals[nonLappingIntervals.size() - 1][1] = min(nonLappingIntervals[nonLappingIntervals.size() - 1][1], intervals[i][1]);
            }
        }
        return intervals.size() - nonLappingIntervals.size();
    }
};
