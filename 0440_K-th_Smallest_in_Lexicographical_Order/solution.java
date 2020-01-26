package cn.huang.leetcode;
/*
440. K-th Smallest in Lexicographical Order  [386]

Given integers n and k, find the lexicographically k-th smallest integer in the range from 1 to n.

Note: 1 ≤ k ≤ n ≤ 109.

Example:

Input:
n: 13   k: 2

Output:
10

Explanation:
The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.

 */


/*
十叉树，比如10 ~ 20在这一层有10个数，如果20小于n，那么再找第三层100 ~ 200，每层step就min(n + 1, n2) - n1

就是每个节点的子节点可以有十个，比如数字1的子节点就是10到19，数字10的子节点可以是100到109，但是由于n大小的限制，
构成的并不是一个满十叉树。我们分析题目中给的例子可以知道，数字1的子节点有4个(10,11,12,13)，
而后面的数字2到9都没有子节点，那么这道题实际上就变成了一个先序遍历十叉树的问题，那么难点就变成了如何计算出每个节点的子节点的个数，
我们不停的用k减去子节点的个数，当k减到0的时候，当前位置的数字即为所求。现在我们来看如何求子节点个数，比如数字1和数字2，
我们要求按字典遍历顺序从1到2需要经过多少个数字，首先把1本身这一个数字加到step中，然后我们把范围扩大十倍，范围变成10到20之前，
但是由于我们要考虑n的大小，由于n为13，所以只有4个子节点，这样我们就知道从数字1遍历到数字2需要经过5个数字，然后我们看step是否小于等于k，
如果是，我们cur自增1，k减去step；如果不是，说明要求的数字在子节点中，我们此时cur乘以10，k自减1，以此类推，直到k为0推出循环，此时cur即为所求：
 */

public class LC_0440_KthSmallestinLexicographicalOrder {

    public int findKthNumber(int n, int k) {
        int cur = 1;
        int step;
        k--;
        while (k > 0) {
            step = calStep(n, cur, cur + 1);
            if (step <= k) {
                k -= step;
                cur++;
            } else {
                k--;
                cur *= 10;
            }
        }
        return cur;
    }

    private int calStep(int n, long n1, long n2) {
        int step = 0;
        while (n1 <= n) {
            step += Math.min(n + 1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return step;
    }
}
