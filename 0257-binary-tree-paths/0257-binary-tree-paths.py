# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        if not root.left and not root.right:
            return [str(root.val)]
        ret = []
        if root.left:
            left = self.binaryTreePaths(root.left)
            ret.extend([str(root.val) + "->" + p for p in left])
        if root.right:
            right = self.binaryTreePaths(root.right)
            ret.extend([str(root.val) + "->" + p for p in right])
        return ret