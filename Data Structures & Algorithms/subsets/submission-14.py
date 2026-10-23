class Solution:

    def sub(self,l1,l2,nums,start):
        l2.append(l1.copy())

        for i in range(start,len(nums)):
            l1.append(nums[i])
            self.sub(l1,l2,nums,i+1)
            l1.pop()

        

    def subsets(self, nums: List[int]) -> List[List[int]]:
        
        l1 = []
        l2 = []

        self.sub(l1,l2,nums,0)

        return l2