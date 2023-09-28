# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def distanceK(self, root, target, k):
        """
        :type root: TreeNode
        :type target: TreeNode
        :type k: int
        :rtype: List[int]
        """
        ans = []

        def dfs(root, t, d):
            if not root:
                return {}, 0
            found = root.val == t.val and d
            ldepths, lfound = dfs(root.left, t, d + 1)
            rdepths, rfound = dfs(root.right, t, d + 1)
            if lfound:
                if d in rdepths:
                    rdepths[d].append(root.val)
                else:
                    rdepths[d] = [root.val]
                #print("found left", d, lfound, rdepths, k + 2 * d - lfound)
                if k + 2 * d - lfound in rdepths:
                    ans.extend(rdepths[k + 2 * d - lfound])
            elif rfound:
                if d in ldepths:
                    ldepths[d].append(root.val)
                else:
                    ldepths[d] = [root.val]
                #print("found right", d, rfound, ldepths, k + 2 * d - rfound)
                if k + 2 * d - rfound in ldepths:
                    ans.extend(ldepths[k + 2 * d - rfound])
            else:
                if d in ldepths:
                    ldepths[d].append(root.val)
                else:
                    ldepths[d] = [root.val]

            for key in rdepths:
                if key in ldepths:
                    ldepths[key].extend(rdepths[key])
                else:
                    ldepths[key] = rdepths[key]

            if found or root.val == t.val:
                print("FOUND")
                if d + k in ldepths:
                    ans.extend(ldepths[d + k])
            
            return ldepths, found or lfound or rfound
        dfs(root, target, 0)
        return ans