class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        result = [0] * n
        stack = []
        # temperatures = [73, 74, 75, 71, 69, 72, 76, 73]
        for i in range(n):
            while stack and temperatures[i]> temperatures[stack[-1]]:
                prev_index = stack.pop()
                result[prev_index] = i - prev_index

            stack.append(i)

        return result        