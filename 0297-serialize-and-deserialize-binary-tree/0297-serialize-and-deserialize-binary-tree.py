# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return "n"
        l = self.serialize(root.left)
        r = self.serialize(root.right)
        return str(root.val) + " " + str(len(l)) + " " + l + " " + str(len(r)) + " " + r
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if data[0] == 'n':
            return None
        
        val = 0
        neg = 1
        while data[0] != " ":
            if data[0] == "-":
                neg = -1
            else:
                val = 10 * val + int(data[0])
            data = data[1:]
        data = data[1:]
        val *= neg

        left = 0
        while data[0] != " ":
            left = 10 * left + int(data[0])
            data = data[1:]
        data = data[1:]

        left_node = self.deserialize(data[:left])
        data = data[left + 1:]

        right = 0
        while data[0] != " ":
            right = 10 * right + int(data[0])
            data = data[1:]
        data = data[1:]

        right_node = self.deserialize(data[:right])
        data = data[right + 1:]

        ret = TreeNode(val)
        ret.left = left_node
        ret.right = right_node
        return ret
        
        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))