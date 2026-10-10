class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        
        mp = {}

        for i in range(len(nums)):
            if nums[i] in mp:
                return nums[i]

            else:
                mp[nums[i]] = mp.get(nums[i],0) + 1

        return -1