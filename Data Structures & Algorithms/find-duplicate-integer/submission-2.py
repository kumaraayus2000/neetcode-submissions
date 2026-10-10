class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        nums.sort()
        l1 = 0
        for i in range(len(nums)-1):
            if nums[i]==nums[i+1]:
                l1 = nums[i]

        return l1