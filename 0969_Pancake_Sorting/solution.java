package cn.huang.leetcode;
/*
969. Pancake Sorting
Given an array A, we can perform a pancake flip: We choose some positive integer k <= A.length, then reverse the
order of the first k elements of A.  We want to perform zero or more pancake flips (doing them one after another
in succession) to sort the array A.

Return the k-values corresponding to a sequence of pancake flips that sort A.  Any valid answer that sorts the array
within 10 * A.length flips will be judged as correct.



Example 1:

Input: [3,2,4,1]
Output: [4,2,4,3]
Explanation:
We perform 4 pancake flips, with k values 4, 2, 4, and 3.
Starting state: A = [3, 2, 4, 1]
After 1st flip (k=4): A = [1, 4, 2, 3]
After 2nd flip (k=2): A = [4, 1, 2, 3]
After 3rd flip (k=4): A = [3, 2, 1, 4]
After 4th flip (k=3): A = [1, 2, 3, 4], which is sorted.

Example 2:

Input: [1,2,3]
Output: []
Explanation: The input is already sorted, so there is no need to flip anything.
Note that other answers, such as [3, 3], would also be accepted.



Note:

    1 <= A.length <= 100
    A[i] is a permutation of [1, 2, ..., A.length]


 */


import java.util.ArrayList;
import java.util.List;

/*


煎饼排序。每次可以把前k个数字进行翻转，问翻转多少次之后可以达到有序状态。

就像一摞煎饼一样，每次能把铲子插入煎饼中的某个位置，然后把铲子之上的煎饼都翻转一下，问一系列位置能使结果是排序的。

把后面的数字先排好，这样再翻转前面的时候就不会影响到后面。所以，先把最大的数字放到最后，然后再把次大的位置放在倒数第二个位置……

如何把最大的数字放到最后呢？一个很简单的想法就是先把它翻转到第一个位置上去！

思路：每次找到还没排序的数字之中"最大"的数字的位置，把这个位置之前的数字翻转，这一步使得最大数字去了最前面。
第二步，再次翻转，把最大位置翻到准确的位置上去。
 */

public class LC_0969_PancakeSorting {
    /*
    Time complexity: O(n^2)
    Space complexity: O(1)

    Put the largest element to its position. Each element requires two flips
    beginning [3, 2, 4, 1]
    largest element: 4, index: 2
    flip1: [4, 2, 3, 1]
    flip2: [1, 3, 2, 4]
    Repeat for [1, 3, 2]…
     */
    public List<Integer> pancakeSort(int[] A) {
        List<Integer> res = new ArrayList<>();
        int n = A.length;
        int max = n;
        for (int i = 0; i < n - 1; i++) {
            // pos is the biggest number
            int pos;
            for (pos = 0; A[pos] != max; pos++) ;  //position of the biggest number
            reverse(A, 0, pos);
            res.add(pos+1);     // result use index + 1
            reverse(A, 0, n - i - 1);
            res.add(n - i -1 + 1);
            max--;
        }
        return res;
    }

    private void reverse(int[] A, int start, int end) {
        while (start <= end) {
            int temp = A[start];
            A[start] = A[end];
            A[end] = temp;
            start++;
            end--;
        }
    }
}
