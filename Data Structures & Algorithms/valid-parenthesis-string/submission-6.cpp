class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for (char c : s) {
            if (c == '(') {
                low++;  // must have one more '('
                high++; // can have one more '('
            } else if (c == ')') {
                low--;  // match a '('
                high--; // also match
            } else { // c == '*'
                low--;  // treat * as ')'
                high++; // or treat * as '('
            }

            if (high < 0) return false; // too many ')'
            if (low < 0) low = 0;       // * treated as empty
        }

        return low == 0;
    }
};
