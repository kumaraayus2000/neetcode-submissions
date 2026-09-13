class Solution {
public:
    bool isPalindrome(string s) {
         string s1 = "";
        for(int i = 0; i < s.size(); i++) {
            if((s[i] >= 'A' && s[i] <= 'Z') ||
               (s[i] >= 'a' && s[i] <= 'z') ||
               (s[i] >= '0' && s[i] <= '9')) {
                s1 = s1 + (char)tolower(s[i]); // ✅ convert to lowercase
            }
        }
        int i = 0, j = s1.size() - 1;
        while(i < j) {
            if(s1[i] != s1[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
