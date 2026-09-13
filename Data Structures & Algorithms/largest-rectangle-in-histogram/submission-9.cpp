class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;           // stack to store indices of bars
        int maxArea = 0;        // store the maximum area found
        int n = heights.size();

        // Loop through all bars + 1 extra iteration for sentinel
        for(int i = 0; i <= n; i++) {
            // Use 0 as sentinel at the end to pop all remaining bars
            int currHeight = (i == n) ? 0 : heights[i];

            // Pop from stack while current bar is smaller than top of stack
            // This means we found the right boundary for the top bar
            while(!s.empty() && currHeight < heights[s.top()]) {
                int height = heights[s.top()]; // height of the popped bar
                s.pop();

                // Width of rectangle with popped bar as smallest height
                // If stack is empty, width = i (all bars to the left)
                // Else, width = distance between current index and new top of stack - 1
                int width = s.empty() ? i : i - s.top() - 1;

                // Calculate area and update maxArea
                maxArea = max(maxArea, height * width);
            }

            // Push current index onto stack
            s.push(i);
        }

        return maxArea; // return the largest rectangle area found
    }
};
