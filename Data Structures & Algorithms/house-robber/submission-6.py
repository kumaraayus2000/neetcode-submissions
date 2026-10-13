class Solution:
    def rob(self, nums: List[int]) -> int:
        
        n = len(nums)
        if n ==1:
            return nums[0]

        dp = [0] * n
        dp[0] = nums[0]
        dp[1] = max(nums[0],nums[1])

        for i in range(2,n):
            skip_current = dp[i-1]

            dp[i] = max(skip_current,nums[i] + dp[i-2])


        x1 =0
        for x in dp:
            x1 = max(x1,x)

        return x1

        