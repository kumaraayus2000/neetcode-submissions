class Solution:

    def sum2(self,l1,l2,nums,target,tsum,start):
        if tsum == target:
            l2.append(l1.copy())
            return

        if tsum>target:
            return

        for i in range(start,len(nums)):

            if i > start and nums[i]==nums[i-1]:
                continue
            l1.append(nums[i])
            self.sum2(l1,l2,nums,target,tsum+nums[i],i+1)
            l1.pop()



    def combinationSum2(self, nums: List[int], target: int) -> List[List[int]]:

        nums.sort()
        l2 = []

        l1 = []
        tsum = 0
        self.sum2(l1,l2,nums,target,tsum,0)
        
        return l2
        