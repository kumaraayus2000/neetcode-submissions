class MinStack:

    def __init__(self):
        self.s1 = []
        self.s2 = []
        

    def push(self, val: int) -> None:
        self.s1.append(val)

        if not self.s2 or val<= self.s2[-1]:
            self.s2.append(val)
        

    def pop(self) -> None:
        if self.s1[-1] == self.s2[-1]:
            self.s2.pop()

        self.s1.pop()
        

    def top(self) -> int:
        return self.s1[-1]
        

    def getMin(self) -> int:
        return self.s2[-1]
        
