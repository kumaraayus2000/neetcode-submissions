# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def height(self,root:Optional[TreeNode])->int:
        if root is None:
            return 0

        l1 = 1 + self.height(root.left)
        r1 = 1 + self.height(root.right)
        return max(l1,r1)

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        
        if root is None:
            return 0

        l1 = self.height(root.left)
        r1 = self.height(root.right)

        return max(max(self.diameterOfBinaryTree(root.left),self.diameterOfBinaryTree(root.right)),l1+r1)
