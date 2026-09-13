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
        // If there are no meetings, we can attend all (trivial case)
        if(intervals.empty()){
            return true;
        }

        // Sort the intervals by start time
        // This helps us easily check for overlapping meetings
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){
            return a.start < b.start;
        });

        // Loop through all intervals and check for overlap
        for(int i = 0; i < intervals.size() - 1; i++){
            // If the end time of the current meeting is greater than
            // the start time of the next meeting, they overlap
            if(intervals[i].end > intervals[i+1].start){
                return false; // overlap detected, cannot attend all
            }
        }

        return true; // no overlaps found, can attend all meetings
    }
};
