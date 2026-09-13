class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);   // frequency of each character
        int l = 0, r = 0;         // sliding window pointers
        int maxfreq = 0;          // max frequency of a single char in current window
        int maxlen = 0;           // longest valid substring length

        // Expand window with right pointer r
        while (r < s.size()) {
            // 1. Add new character s[r] into the window
            cnt[s[r] - 'A']++;
            maxfreq = max(maxfreq, cnt[s[r] - 'A']);

            // 2. If replacements needed > k, shrink from left
            // replacements = window size - most frequent char count
            while ((r - l + 1) - maxfreq > k) {
                cnt[s[l] - 'A']--;  // remove leftmost char
                l++;                // shrink window
            }

            // 3. Update best result with current valid window
            maxlen = max(maxlen, r - l + 1);

            // 4. Move right pointer forward
            r++;
        }

        return maxlen;
    }
};
