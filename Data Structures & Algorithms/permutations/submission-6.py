class Solution:

    def add(self, l1:List[int], nums:List[int], l2:List[int]):

        if len(l1) == len(nums):
            l2.append(l1.copy())
            return


        for num in nums:
            if num in l1:
                continue

            l1.append(num)
            self.add(l1,nums,l2)
            l1.pop()


    def permute(self, nums: List[int]) -> List[List[int]]:
        l1 = []
        l2 = []

        self.add(l1,nums,l2)

        return l2