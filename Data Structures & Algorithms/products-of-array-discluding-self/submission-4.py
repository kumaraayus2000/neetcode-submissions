class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        prefix =1
        n = len(nums)
        
        v1 = [1] * n

        for i in range(len(nums)):
            v1[i] = prefix
            prefix= prefix* nums[i]
        
        postfix = 1

        for i in range(n-1,-1,-1):
            v1[i] = postfix* v1[i]
            postfix = postfix * nums[i]

        return v1