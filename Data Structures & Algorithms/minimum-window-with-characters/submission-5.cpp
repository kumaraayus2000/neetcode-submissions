class Solution {
public:
    string minWindow(string s, string t) {
        // Frequency map for the target string t
        vector<int> v2(128, 0);  // As we might have lowercase characters too
        // Frequency map for the current window in s
        vector<int> v1(128, 0);
        string s1 = "";         // Result to store the minimum window
        int minLength = INT_MAX; // Variable to store the minimum length of the window

        // Step 1: Build frequency map for string t
        for (int i = 0; i < t.size(); i++) {
            v2[t[i]]++;  // Use ASCII values directly
        }

        int i = 0, j = 0;  // Sliding window pointers
        int count = 0;  // Count of characters matched in the window

        // Step 2: Expand the window by moving the right pointer (j)
        while (j < s.size()) {
            // Add current character to the window
            if (v2[s[j]] > 0) {
                v1[s[j]]++;
                // If current character in window matches the frequency in t
                if (v1[s[j]] <= v2[s[j]]) {
                    count++;
                }
            }

            // Step 3: Once we have all characters from t in the window, try to shrink the window
            while (count == t.size()) {
                // Update the minimum window
                if (j - i + 1 < minLength) {
                    minLength = j - i + 1;
                    s1 = s.substr(i, j - i + 1);
                }

                // Shrink from left
                if (v2[s[i]] > 0) {
                    v1[s[i]]--;
                    // If the character at left is no longer contributing to a valid window
                    if (v1[s[i]] < v2[s[i]]) {
                        count--;
                    }
                }
                i++;  // Move left pointer to shrink the window
            }

            j++;  // Move right pointer to expand the window
        }

        return s1;
    }
};
