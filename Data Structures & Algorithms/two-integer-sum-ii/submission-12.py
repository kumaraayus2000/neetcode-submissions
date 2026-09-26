from typing import List

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:

        # Left pointer
        i = 0

        # Right pointer
        j = len(numbers) - 1

        while i < j:

            current_sum = numbers[i] + numbers[j]

            # Sum is too small
            # Move left pointer to get a larger number
            if current_sum < target:
                i += 1

            # Sum is too large
            # Move right pointer to get a smaller number
            elif current_sum > target:
                j -= 1

            # Found the target
            else:
                return [i + 1, j + 1]

        return []