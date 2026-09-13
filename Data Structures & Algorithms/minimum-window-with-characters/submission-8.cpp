class Solution {
public:
    string minWindow(string s, string t) {
        // Frequency arrays for the window (v1) and target string t (v2)
        vector<int> v1(128, 0);  // v1: frequency map for current window in s
        vector<int> v2(128, 0);  // v2: frequency map for string t

        // Step 1: Build frequency map for string t
        for (int i = 0; i < t.size(); i++) {
            v2[t[i]]++;  // Record frequencies of characters in t
        }

        int i = 0, j = 0;      // Sliding window pointers
        int minlen = INT_MAX;  // Store the minimum window length found
        int count = 0;         // Keep track of how many characters from t are matched
        string s1 = "";        // Result string (minimum window)

        // Step 2: Expand the window by moving the right pointer (j)
        while (j < s.length()) {

            // If the character in s[j] is part of t, increase its count in v1
            if (v2[s[j]] > 0) {
                v1[s[j]]++;
                // If current window matches the frequency of that character in t, increment count
                if (v1[s[j]] <= v2[s[j]]) {
                    count++;
                }
            }

            // Step 3: Shrink the window from the left when we have all characters from t
            while (count == t.size()) {
                // If the window is valid, check if it's the smallest window found
                if (minlen > j - i + 1) {
                    minlen = j - i + 1;
                    s1 = s.substr(i, j - i + 1);  // Update the result substring
                }

                // Try to shrink the window by moving the left pointer (i)
                if (v2[s[i]] > 0) {
                    v1[s[i]]--;  // Decrease count of the character at i in v1
                    // If the character at i is no longer needed, decrease count
                    if (v1[s[i]] < v2[s[i]]) {
                        count--;  // One character match is lost
                    }
                }
                i++;  // Move left pointer to shrink window
            }

            j++;  // Move right pointer to expand the window
        }

        return s1;  // Return the minimum window found
    }
};
