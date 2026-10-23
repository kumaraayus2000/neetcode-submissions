class Solution:

    def sum1(self,nums,l1,l2,tsum,target,start):

        if tsum == target:
            l2.append(l1.copy())
            return

        if tsum>target:
            return

        for i in range(start,len(nums)):
            l1.append(nums[i])

            self.sum1(nums,l1,l2,tsum+nums[i],target,i)
            l1.pop()
        


    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        l1 = []
        l2 = []
        tsum = 0
        self.sum1(nums,l1,l2,0,target,0)

        return l2