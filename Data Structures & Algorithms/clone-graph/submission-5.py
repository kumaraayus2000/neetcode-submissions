"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    
    def dfs(self,node,mp):

        if node in mp:
            return mp[node]

        clone = Node(node.val)
        mp[node] = clone

        for n1 in node.neighbors:

            cloned = self.dfs(n1,mp)
            clone.neighbors.append(cloned)

        return clone
        
    
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if node is None:
            return None
        mp ={}
        return self.dfs(node,mp)


        