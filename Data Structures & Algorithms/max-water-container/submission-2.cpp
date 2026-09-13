class Solution {
public:
    int maxArea(vector<int>& heights) {
        
       int i = 0;                      // left pointer
        int j = heights.size() - 1;     // right pointer
        int area = 1;                   // current calculated area
        int marea = INT_MIN;             // maximum area found so far
        // Two-pointer approach to find max area
        while (i < j) {
            // Calculate current area: width = (j - i), height = min of the two lines
            area = min(heights[i], heights[j]) * (j - i);
            // Update maximum area if current is bigger
            marea = max(marea, area);
            // Move the pointer with the smaller height inward
            // Because moving the taller one won’t increase area (height is limited by shorter line)
            if (heights[i] > heights[j]) {
                j--;
            } else {
                i++;
            }
        }
        return marea; // Return the maximum area found
    }
};
