# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def minDepth(self, t):
        """
        :type t: TreeNode
        :rtype: int
        """
        if t is None:
            return 0
        if self.is_leaf(t):
            return 1
        
        if t.left and t.right:
            return 1 + min(self.minDepth(t.left), self.minDepth(t.right))
        if t.right:
            return 1 + self.minDepth(t.right)
        if t.left:
            return 1 + self.minDepth(t.left)
        
    
    def is_leaf(self, t):
        if t is None:
            return True
        if t.left is None and t.right is None:
            return True
        else:
            return False
        