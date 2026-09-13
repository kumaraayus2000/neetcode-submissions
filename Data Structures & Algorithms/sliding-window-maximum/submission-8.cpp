class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int max1 = INT_MIN;  // Initialize max1 with the smallest possible value
        vector<int> v1;

        int j = 0,l=0;  // Right pointer of the sliding window
        while (j < nums.size()-k+1) {

            max1 = INT_MIN;  // Reset max1 for each window
            int l1 = j;  // Left pointer of the window
            
            // Calculate the maximum of the current window of size k
            while (j < l1 + k && j < nums.size() ) {
                max1 = max(nums[j], max1);  // Find the max in the window
                j++;
            }
            
            v1.push_back(max1);  // Store the max of the current window
            j = l1 + 1;  // Move the left pointer to the next position
       
        }
        return v1;
    }
};
