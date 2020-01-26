package cn.huang.leetcode;

import cn.huang.leetcode.common.TreeNode;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

/*
508. Most Frequent Subtree Sum
 Given the root of a tree, you are asked to find the most frequent subtree sum.
 The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that
 node (including the node itself). So what is the most frequent subtree sum value?
 If there is a tie, return all the values with the highest frequency in any order.

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
 */

/*
    https://www.youtube.com/watch?v=mqFIWYBjrkw
 */
public class LC_0508_MostFrequentSubtreeSum {
    private int maxSum = 0;

    public int[] findFrequentTreeSum(TreeNode root) {
        Map<Integer, Integer> sumToCount = new HashMap<>();


        if (root != null)
            countSum(root, sumToCount);

        List<Integer> maxSums = new LinkedList<>();

        for (Map.Entry<Integer, Integer> pair : sumToCount.entrySet()) {
            int count = pair.getValue();
            if (count == maxSum)
                maxSums.add(pair.getKey());
        }

        int[] result = new int[maxSums.size()];
        int i = 0;
        for (int sum : maxSums) {
            result[i++] = sum;
        }
        return result;
    }

    private int countSum(TreeNode root, Map<Integer, Integer> sumToCount)
    {
        int sum = root.val;
        if(root.left != null)
        {
            sum += countSum(root.left, sumToCount);
        }
        if(root.right != null)
        {
            sum += countSum(root.right, sumToCount);
        }
        int count = sumToCount.containsKey(sum) ? sumToCount.get(sum) + 1:1;
        sumToCount.put(sum, count);
        maxSum = Math.max(maxSum, count);
        return sum;
    }
}
