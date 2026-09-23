class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        
        mp = {}

        for l1 in nums:
            mp[l1] = mp.get(l1,0) + 1

        for l2 in nums:
            if mp[l2] >1:
                return True

        return False