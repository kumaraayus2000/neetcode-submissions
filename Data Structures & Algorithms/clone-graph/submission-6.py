"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional


class Solution:

    def dfs(self, node, mp):

        # If this node was already cloned,
        # return the existing cloned node.
        # This prevents infinite recursion in cycles.
        if node in mp:
            return mp[node]

        # Create a new clone with the same value.
        clone = Node(node.val)

        # Store mapping:
        # original node -> cloned node
        #
        # Important:
        # store it BEFORE exploring neighbors
        # because the graph can contain cycles.
        mp[node] = clone

        # Visit every neighbor of the original node.
        for neighbor in node.neighbors:

            # Recursively clone the neighbor.
            cloned_neighbor = self.dfs(neighbor, mp)

            # Connect current cloned node
            # to the cloned neighbor.
            clone.neighbors.append(cloned_neighbor)

        # Return the fully cloned node.
        return clone


    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:

        # If graph is empty, return None.
        if node is None:
            return None

        # Hashmap to remember already cloned nodes.
        #
        # original node -> cloned node
        mp = {}

        # Start DFS from the given node.
        return self.dfs(node, mp)