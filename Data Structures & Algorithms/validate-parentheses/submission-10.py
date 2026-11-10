class Solution:
    def isValid(self, s: str) -> bool:
        s1 = []

        for x in s:
            if x=='[' or x=='{' or x=='(':
                s1.append(x)
            else:
                if not s1:
                    return False

                if x==']' and s1[-1]=='[':
                    s1.pop()
                elif x=='}' and s1[-1] =='{':
                    s1.pop()
                elif x==')' and s1[-1]=='(':
                    s1.pop()
                else:
                    return False

        if not s1:
            return True

        return False
            

