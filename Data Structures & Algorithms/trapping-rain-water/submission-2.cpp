class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); // total number of bars

        // Arrays to store the max height to the left and right of each bar
        int leftmax[n] = {0};
        int rightmax[n] = {0};

        int ans = INT_MIN; // keeps track of running max from the left
        // Fill leftmax array
        for (int i = 0; i < n; i++) {
            ans = max(height[i], ans);  // max height so far from the left
            leftmax[i] = ans;           // store it
        }

        int ans1 = INT_MIN; // keeps track of running max from the right
        // Fill rightmax array
        for (int j = n - 1; j >= 0; j--) {
            ans1 = max(height[j], ans1); // max height so far from the right
            rightmax[j] = ans1;           // store it
        }

        int sum = 0; // total trapped water
        // Water trapped at each index = min(leftmax, rightmax) - height
        for (int i = 0; i < height.size(); i++) {
            sum = sum + min(leftmax[i], rightmax[i]) - height[i];
        }

        return sum; // total trapped water
    }
};
