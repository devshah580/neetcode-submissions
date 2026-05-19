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

        std::vector<std::vector<Interval>> result;
        for(int i = 0; i < intervals.size(); i++) {
            bool found = false;
            for(int j = 0; j < result.size(); j++) {
                if(result[j][result[j].size() - 1].end <= intervals[i].start) {
                    result[j].push_back(intervals[i]);
                    found = true;
                    break;
                }
            }
            if(!found) {
                result.push_back(std::vector<Interval>());
                result[result.size() - 1].push_back(intervals[i]);
            }
        }

        return result.size();
    }
};
