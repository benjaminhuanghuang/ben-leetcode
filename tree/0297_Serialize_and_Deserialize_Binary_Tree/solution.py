# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:
    def serialize_my(self, root):
        if not root:
            return "[]"

        res = ""
        self.serializeHelper(root, res)
        res = res[:-1]  # remove last ","
        return "[" + res + "]"

    def serializeHelper(self, node, res):
        if node:
            res += str(node.val) + ","
            self.serializeHelper(node.left, res)
            self.serializeHelper(node.right, res)
        else:
            res += "null,"

    def deserialize_my(self, data):
        if data == "[]":
            return None
        vals = data[1:-1].split(',')
        root = self.deserializeHelper(vals)
        return root

    def deserializeHelper(self, vals):
        if len(vals) == 0:
            return None
        v = vals[0]
        vals.pop(0)
        if v == "null":
            return None
        node = TreeNode(int(v))
        node.left = self.deserializeHelper(vals)
        node.right = self.deserializeHelper(vals)
        return node

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return "[]"

        queue = [root]
        index = 0
        while index < len(queue):
            if queue[index] is not None:
                queue.append(queue[index].left)
                queue.append(queue[index].right)
            index += 1

        while queue[-1] is None:
            queue.pop()

        return '{0}'.format(','.join([str(node.val) if node is not None else 'null'
                                      for node in queue]))

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        if not data or data == "[]":
            return None

        values = data[1:-1].split(",")
        root = TreeNode(int(values[0]))
        nodes = [root]
        index = 0
        is_left = True
        for value in values[1:]:
            if value != "null":
                node = TreeNode(int(value))
                if is_left:
                    nodes[index].left = node
                else:
                    nodes[index].right = node
                nodes.append(node)
            if not is_left:
                index += 1
            is_left = not is_left
        return root


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))


values = "[1,2,3,null,null,4,5]"
codec = Codec()
root = codec.deserialize_my(values)
print root

data = codec.serialize_my(root)
print data
