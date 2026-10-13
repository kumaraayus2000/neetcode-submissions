class Solution:
    def rob(self, nums: list[int]) -> int:

        n = len(nums)

        # Edge case:
        # If there is only one house, rob that house.
        if n == 1:
            return nums[0]

        # dp[i] = maximum money we can rob
        # from house 0 up to house i
        dp = [0] * n

        # If we only consider the first house,
        # the best answer is to rob it.
        dp[0] = nums[0]

        # For the first two houses,
        # we cannot rob both because they are adjacent.
        # So we take the maximum of the two.
        dp[1] = max(nums[0], nums[1])

        # Start from the third house
        for i in range(2, n):

            # Option 1:
            # Skip the current house.
            # Then we keep the best answer from the previous house.
            skip_current = dp[i - 1]

            # Option 2:
            # Rob the current house.
            # Since adjacent houses cannot both be robbed,
            # we add nums[i] to the best answer from i - 2.
            rob_current = nums[i] + dp[i - 2]

            # Take the better of the two choices.
            dp[i] = max(skip_current, rob_current)

        # The last dp value contains the maximum
        # money we can rob from all houses.
        return dp[n - 1]