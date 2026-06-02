/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
            if(a.start < b.start) { return true;
            } else if(b.start < a.start) { return false;
            } else { return a.end < b.end; }
        });

        priority_queue<int, vector<int>, greater<int>> heap;
        for(int i = 0; i < intervals.size(); i++) {
            if(heap.size() > 0 && heap.top() <= intervals[i].start) {
                heap.pop();
            }

            heap.push(intervals[i].end);
        }

        return heap.size();
    }
};
