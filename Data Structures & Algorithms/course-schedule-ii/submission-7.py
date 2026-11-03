class Solution:

    def dfs(self, graph,state,idx,res):
        if state[idx]==1:
            return False

        if state[idx]==2:
            return True

        state[idx] = 1

        for x1 in graph[idx]:
            if not self.dfs(graph,state,x1,res):
                return False

        state[idx] = 2
        res.append(idx)
        return True


    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:

        graph = [[] for _ in range (numCourses)]

        for u,v in prerequisites:
            graph[u].append(v)

        state = [0] * numCourses
        res = []
        for num in range (numCourses):
            if not self.dfs(graph,state,num,res):
                return []

        return res

        