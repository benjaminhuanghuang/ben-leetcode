'''
508. Most Frequent Subtree Sum

Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined
as the sum of all the node values formed by the subtree rooted at that node (including the node itself).

So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest
frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.
'''


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def findFrequentTreeSum_better(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []
        res = []
        freq_dict = {}
        self.helper(root, freq_dict)
        # sort sum by freq
        sorted_keys = sorted(freq_dict, key=lambda x: freq_dict[x], reverse=True)
        max_freq = freq_dict[sorted_keys[0]]
        for k, v in freq_dict.iteritems():
            if v == max_freq:
                res.append(k)
        return res

        # put iteration and sum to one function!

    def helper(self, root, freq_dict):
        if not root:
            return 0
        left_sum = self.helper(root.left, freq_dict) if root.left else 0
        right_sum = self.helper(root.right, freq_dict) if root.right else 0
        sum = left_sum + right_sum + root.val
        if sum in freq_dict:
            freq_dict[sum] += 1
        else:
            freq_dict[sum] = 1
        return sum

    def findFrequentTreeSum(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        res = []
        freq_dict = {}
        self.treeSumIteration(root, freq_dict)
        # sort sum by freq
        sorted_keys = sorted(freq_dict, key=lambda x: freq_dict[x], reverse=True)
        max_freq = freq_dict[sorted_keys[0]]
        for k, v in freq_dict.iteritems():
            if v == max_freq:
                res.append(k)
        return res

    def treeSumIteration(self, root, freq_dict):
        if root:
            sum = self.treeSum(root)
            if sum in freq_dict:
                freq_dict[sum] += 1
            else:
                freq_dict[sum] = 1
            self.treeSumIteration(root.left, freq_dict)
            self.treeSumIteration(root.right, freq_dict)

    def treeSum(self, root):
        if not root:
            return 0
        sum = root.val + self.treeSum(root.left) + self.treeSum(root.right)
        return sum


tree = TreeNode(5)
tree.left = TreeNode(2)
tree.right = TreeNode(-3)

s = Solution()
print s.findFrequentTreeSum(tree)
