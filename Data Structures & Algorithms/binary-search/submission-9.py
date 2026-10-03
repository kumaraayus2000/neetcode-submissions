from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:

        start = 0
        end = len(nums) - 1

        # Keep searching while valid range exists
        while start <= end:

            mid = (start + end) // 2

            # Target found
            if nums[mid] == target:
                return mid

            # Target is smaller, search left
            elif nums[mid] > target:
                end = mid - 1

            # Target is larger, search right
            else:
                start = mid + 1

        # Target does not exist
        return -1