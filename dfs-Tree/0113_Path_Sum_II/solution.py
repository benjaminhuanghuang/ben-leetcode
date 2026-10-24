'''
113. Path Sum II

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]

'''


class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """

        solution = []
        self.pathSumRec(root, sum, 0, [], solution)
        return solution

    def pathSumRec(self, root, sum, tempSum, tempList, solution):
        if root == None:
            return
        tempList.append(root.val)
        tempSum += root.val
        if root.left == None and root.right == None:
            if tempSum == sum:
                solution.append(list(tempList))
        else:
            self.pathSumRec(root.left, sum, tempSum, tempList, solution)
            self.pathSumRec(root.right, sum, tempSum, tempList, solution)
        tempList.pop()

    def pathSum_2(self, root, sum):
        def dfs(root, currsum, valuelist):
            if root.left == None and root.right == None:
                if currsum == sum: res.append(valuelist)
            if root.left:
                dfs(root.left, currsum + root.left.val, valuelist + [root.left.val])
            if root.right:
                dfs(root.right, currsum + root.right.val, valuelist + [root.right.val])

        res = []
        if root == None:
            return []
        dfs(root, root.val, [root.val])
        return res
