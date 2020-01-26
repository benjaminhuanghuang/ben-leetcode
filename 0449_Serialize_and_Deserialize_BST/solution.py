'''
449. Serialize and Deserialize BST


'''


class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if root is None:
            return "#"
        return str(root.val) + " " + self.serialize(root.left) + " " + self.serialize(root.right)

    def deserialize(self, dataStr):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        data = dataStr.split(" ")
        return self.deserialize_helper(data, [0])

    def deserialize_helper(self, data, i):
        if data[i[0]] == "#":
            return None
        root = TreeNode(int(data[i[0]]))
        i[0] += 1
        root.left = self.deserialize_helper(data, i)
        i[0] += 1
        root.right = self.deserialize_helper(data, i)
        return root

root = TreeNode(2)
root.left = TreeNode(1)
root.right = TreeNode(3)

codec = Codec()
s = codec.serialize(root)
codec.deserialize(s)