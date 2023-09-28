# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def sym(l, r):
            if l == None and r == None:
                return True
            elif l == None or r == None:
                return False
            if l.val == r.val:
                return sym(l.left, r.right) and sym(l.right, r.left)
            else:
                return False
            
        if not root:
            return True
        return sym(root.left, root.right)