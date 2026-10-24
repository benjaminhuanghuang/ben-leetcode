class Solution:
    # @param {TreeNode} root
    # @return {string[]}
    def binaryTreePaths(self, root):
        paths = []
        if not root:
            return paths

        self.build_path(root, paths, [])
        return paths


    def build_path(self, node, result, tmp):
        tmp.append(str(node.val))
        if node.left is None and node.right is None:
            result.append('->'.join(tmp))
            tmp.pop()
            return

        if node.left:
            self.build_path(node.left, result, tmp);

        if node.right:
            self.build_path(node.right, result, tmp)

        tmp.pop()
