class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        // Result array initialized with 0s (default: no warmer day found)
        vector<int> v1(n, 0);
        
        // Monotonic stack to store indices of days
        // The temperatures of these indices will be in strictly increasing order (from top to bottom)
        stack<int> s;

        // Traverse from the last day to the first
        for (int i = n - 1; i >= 0; i--) {

            // Pop all indices from the stack where the temperature is 
            // less than or equal to the current day's temperature
            // These days cannot be the "next warmer day" for the current day
            while (!s.empty() && t[s.top()] <= t[i]) {
                s.pop();
            }

            // If the stack is not empty, the top element is the index of the next warmer day
            if (!s.empty()) {
                v1[i] = s.top() - i;  // Number of days to wait
            }
            // If the stack is empty, v1[i] stays 0 (no warmer day ahead)

            // Push the current day's index onto the stack
            s.push(i);
        }

        return v1;
    }
};
