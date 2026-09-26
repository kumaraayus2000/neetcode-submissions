class Solution:

    def encode(self, strs: List[str]) -> str:
        s1 = ""
        for str1 in strs:
            s1 = s1 + str(len(str1)) + "#" +str1

        return s1

    def decode(self, s: str) -> List[str]:
        l1 = []
        i = 0

        while i< len(s):

            j = i

            while s[j]!='#':
                j+=1

            length = int(s[i:j])
            start = j+1
            s1 = s[start:start + length]

            l1.append(s1)

            i = start + length

        return l1



