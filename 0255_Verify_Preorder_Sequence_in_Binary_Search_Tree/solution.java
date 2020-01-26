package cn.huang.leetcode;

import java.util.Stack;

/*
255. Verify Preorder Sequence in Binary Search Tree



 */

/*
https://www.youtube.com/watch?v=fH3XUXdinCs

     5
    / \
   2   6
  / \
 1   3


{5, 2, 1, 3, 6}

对于一个BST的preorder来说, 如果某段序列为一个递减序列, 说明这是一段沿着左子树的路径.
直到碰到一个比前一个大的值, 说明此时已经来到某个结点的右子树上了,
而此时可以得出一个此后序列的下界值, 也就是此后序列的任意一个值必须要比这个结点的父结点的值大,
因为对于搜索二叉树来说根节点左边的都比根节点小, 而根节点右边的都比根节点大, 所以既然现在已经来到某个结点(设为A)的右子树上,
那么此后任何结点的值必然比A的值大.

那么当我们碰到一个比之前结点大的值如何找到他的父结点呢? 可以借助一个栈, 即如果当前结点比栈顶元素小, 就入栈,
如果当前值大于栈顶值, 则让所有比当前结点小的值都出栈, 直到栈顶元素比当前结点大, 则最后一个出栈的比当前结点小的值就是当前结点的父结点,
我们只要在栈元素出栈的时候更新最小下界再将当前元素入栈即可.
 */
public class LC_0255_VerifyPreorderSerializationInBinarySearchTree {
    public boolean verifyPreorder(int[] preorder) {
        Stack<Integer> stack = new Stack<>();
        int min = Integer.MIN_VALUE;

        for (int num : preorder) {
            // num is on right side but smaller than root.
            if (num < min) {
                return false;
            }
            // if num is in right subtree of stack top,
            // keep removing items smaller than num and make the last removed item as new root
            while (!stack.isEmpty() && num > stack.peek()) {
                min = stack.pop();
            }
            stack.push(num);
        }

        return true;
    }

    public boolean verifyPreorder2(int[] preorder) {
        return helper(preorder, 0, preorder.length - 1, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    private boolean helper(int[] preorder, int start, int end, int min, int max) {
        if (start > end)
            return true;
        int rootVal = preorder[start], i = 0;
        if (rootVal <= min || rootVal >= max)
            return false;
        for (i = start + 1; i <= end; ++i) {
            if (preorder[i] >= rootVal) break;
        }
        return helper(preorder, start + 1, i - 1, min, rootVal) && helper(preorder, i, end, rootVal, max);
    }
}
