class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = {}

        for s1 in strs:
            s2 = "".join(sorted(s1))

            if s2 not in mp:
                mp[s2]= []

            mp[s2].append(s1)

        
        r1 = []

        for v1 in mp.values():
            r1.append(v1)

        return r1