package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
851. Loud and Rich

In a group of N people (labelled 0, 1, 2, ..., N-1), each person has different amounts of money, and different levels
of quietness.

For convenience, we'll call the person with label x, simply "person x".

We'll say that richer[i] = [x, y] if person x definitely has more money than person y.  Note that richer may only be
a subset of valid observations.

Also, we'll say quiet[x] = q if person x has quietness q.

Now, return answer, where answer[x] = y if y is the least quiet person (that is, the person y with the smallest value
of quiet[y]), among all people who definitely have equal to or more money than person x.



Example 1:

Input: richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
Output: [5,5,2,5,4,5,6,7]
Explanation:
answer[0] = 5.
Person 5 has more money than 3, which has more money than 1, which has more money than 0.
The only person who is quieter (has lower quiet[x]) is person 7, but
it isn't clear if they have more money than person 0.

answer[7] = 7.
Among all people that definitely have equal to or more money than person 7
(which could be persons 3, 4, 5, 6, or 7), the person who is the quietest (has lower quiet[x])
is person 7.

The other answers can be filled out with similar reasoning.

Note:

    1 <= quiet.length = N <= 500
    0 <= quiet[i] < N, all quiet[i] are different.
    0 <= richer.length <= N * (N-1) / 2
    0 <= richer[i][j] < N
    richer[i][0] != richer[i][1]
    richer[i]'s are all different.
    The observations in richer are all logically consistent.


 */
/*
给你一张有向图，每个节点上又一个val，问对于每个节点，能到达这个节点的val最小的节点的编号。
题目给出了有钱人之间的对比，在richer中第一个数字的人比第二个数字的人有钱。quiet值代表每个人的安静指数，数字越大代表越吵。

我们要做的是，找出对于每个人，比他有钱的人还比他安静是谁。

人的编号从0到n-1，每个人有一定的钱和度，并且都不相同
返回ans，ans[i]代表比i这个人钱多的人中，度最小的人的编号
数据（节点）长度500，边长度不超过250000，故显然对边分析时，n^2复杂度不可行

 */
public class LC_0851_LoudandRich {
    public int[] loudAndRich(int[][] richer, int[] quiet) {
        // A directed acyclic graph -> tree
        // Find the quietest id of its subtree
        int len = quiet.length;
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < len; i++) {
            graph.add(new ArrayList<>());
        }
        for (int[] pair : richer) {
            graph.get(pair[1]).add(pair[0]);
        }
        int[] result = new int[len];
        Arrays.fill(result, -1);
        for (int i = 0; i < len; i++) {
            if (result[i] == -1) {
                dfs(graph, result, i, quiet);
            }
        }
        return result;
    }

    private void dfs(List<List<Integer>> graph, int[] result, int curr, int[] quiet) {
        int minIndex = curr;
        for (int next : graph.get(curr)) {
            if (result[next] == -1) {
                dfs(graph, result, next, quiet);
            }
            if (quiet[result[next]] < quiet[minIndex]) {
                minIndex = result[next];
            }
        }
        result[curr] = minIndex;
    }
}
