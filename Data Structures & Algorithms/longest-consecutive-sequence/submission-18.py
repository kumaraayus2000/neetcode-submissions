class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        nums.sort()
        curr = 1
        l1 = 1

        for i in range(len(nums)-1):
            if nums[i] == nums[i+1]:
                continue

            if nums[i]+1 == nums[i+1]:
                curr +=1
            else:
                l1 = max(curr,l1)
                curr = 1

        l1 = max(curr,l1)
        
        return l1
            

            