from typing import List

class Solution:

    def robsum(self, nums):

        # If there is only one house,
        # the best choice is to rob that house.
        if len(nums) == 1:
            return nums[0]

        n1 = len(nums)

        # dp[i] = maximum money we can rob
        # from house 0 to house i
        dp = [0] * n1

        # First house
        dp[0] = nums[0]

        # For first two houses,
        # choose the one with more money.
        dp[1] = max(nums[0], nums[1])

        # Standard House Robber DP
        for i in range(2, n1):

            # Option 1: skip current house
            skip_current = dp[i - 1]

            # Option 2: rob current house
            # and add best result from i-2
            rob_current = nums[i] + dp[i - 2]

            dp[i] = max(skip_current, rob_current)

        # Last dp value contains the best answer
        return dp[n1 - 1]


    def rob(self, nums: List[int]) -> int:

        # Edge case:
        # If there is only one house,
        # we cannot exclude first/last because both are same house.
        if len(nums) == 1:
            return nums[0]

        # Houses are circular, so first and last
        # cannot both be robbed.

        # Case 1: exclude first house
        exclude_first = self.robsum(nums[1:])

        # Case 2: exclude last house
        exclude_last = self.robsum(nums[:-1])

        # Take the better of the two cases
        return max(exclude_first, exclude_last)