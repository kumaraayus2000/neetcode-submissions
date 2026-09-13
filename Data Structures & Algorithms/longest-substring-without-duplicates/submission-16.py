class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        mp = {}
        l1 = 0
        l = 0
        for i in range(len(s)):
            if s[i] in mp:
                l = max(mp[s[i]]+1,l)
                
            mp[s[i]] = i
            l1 = max(l1,i-l+1)
            

        return l1



        