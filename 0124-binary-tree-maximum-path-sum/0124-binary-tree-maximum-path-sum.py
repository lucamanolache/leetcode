# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        global ms
        ms = -9999999999

        def mps(root):
            global ms

            if not root:
                return -9999999999

            ls = mps(root.left)
            rs = mps(root.right)

            ms = max(ms, root.val + ls, root.val + rs, root.val + ls + rs, root.val)

            return max(root.val + ls, root.val + rs, root.val)
        
        mps(root)
        return ms