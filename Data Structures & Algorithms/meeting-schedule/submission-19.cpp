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
        // Sort intervals by start time
        if(intervals.empty()){
            return true;
        }
       sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){
            return a.start < b.start;
        });
        
        // Check for overlapping intervals
        for(int i = 0; i < intervals.size() - 1; i++){
            if(intervals[i].end > intervals[i+1].start){
                return false; // overlap detected
            }
        }
        
        return true; 
       // no overlap, can attend all meetings
    }
};

