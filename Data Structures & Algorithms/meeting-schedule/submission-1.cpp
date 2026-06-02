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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
            if(a.start < b.start) {return true;}
            else if(b.start < a.start) {return false;}
            else {return a.end < b.end;}
        });

        for(int i = 0; i < (int)intervals.size() - 1; i++) {
            if(intervals[i].end > intervals[i + 1].start) {
                return false;
            }
        }
        return true;
    }
};
