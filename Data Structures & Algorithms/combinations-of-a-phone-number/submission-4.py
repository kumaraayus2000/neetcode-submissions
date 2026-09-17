class Solution:

    def part(self,digits,mp,ind,current,res):

        if ind == len(digits):
            res.append(current)
            return

        l1 = mp[digits[ind]]

        for ch in l1:
            self.part(digits,mp,ind+1,current+ch,res)



    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        mp = {
            "2":"abc",
            "3":"def",
            "4":"ghi",
            "5":"jkl",
            "6":"mno",
            "7":"pqrs",
            "8":"tuv",
            "9":"wxyz"
        }
        res = []
        self.part(digits,mp,0,"",res)

        return res


        