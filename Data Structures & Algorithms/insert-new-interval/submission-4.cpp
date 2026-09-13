class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int i=0; // pointer to iterate through intervals
        vector<vector<int>>result; // store the final merged intervals
        int n = intervals.size(); // total number of intervals

        // iterate through all intervals
        while(i<n){
            if(intervals[i][1]<newInterval[0]){ // { (1,2),(3,4) interval}
                // current interval ends before newInterval starts → no overlap
                result.push_back(intervals[i]);
            }else if(intervals[i][0]>newInterval[1]){ // {interval(1,2), (3,4)}
                // current interval starts after newInterval ends → no overlap
                break; // stop merging, handle later
            }else{
                // intervals overlap → merge by updating newInterval start and end
                newInterval[0] = min(newInterval[0],intervals[i][0]);
                newInterval[1] = max(newInterval[1],intervals[i][1]);
            }
        i++; // move to next interval
        }

        // add the merged newInterval to result
        result.push_back(newInterval);

        // add remaining intervals after newInterval
        while(i<n){
            result.push_back(intervals[i]);
            i++;
        }

        return result; // return final intervals
    }
};
