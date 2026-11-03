class Solution:

    def dfs(self,graph,state,ind):

        if state[ind]==1:
            return False

        if state[ind]==2:
            return True

        state[ind]=1

        for x1 in graph[ind]:
            if not self.dfs(graph,state,x1):
                return False
            
        state[ind] = 2

        return True

    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
        graph = [[] for _ in range (numCourses)]

        for u,v in prerequisites:
            graph[u].append(v)


        state = [0] * numCourses


        for num in range(numCourses):

            if not self.dfs(graph,state,num):
                return False
        
        return True