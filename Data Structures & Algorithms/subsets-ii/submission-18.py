class Solution:

    def sub(self,l1,l2,nums,start):
        l2.append(l1.copy())

        for i in range(start,len(nums)):
            if i>start and nums[i]==nums[i-1]:
                continue
                
            l1.append(nums[i])
            self.sub(l1,l2,nums,i+1)
            l1.pop()


    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        l1 = []
        l2 = []
        nums.sort()
        self.sub(l1,l2,nums,0)

        return l2