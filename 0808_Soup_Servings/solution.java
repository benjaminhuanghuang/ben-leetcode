package cn.huang.leetcode;
/*
808. Soup Servings

There are two types of soup: type A and type B. Initially we have N ml of each type of soup. There are four kinds of operations:

    Serve 100 ml of soup A and 0 ml of soup B
    Serve 75 ml of soup A and 25 ml of soup B
    Serve 50 ml of soup A and 50 ml of soup B
    Serve 25 ml of soup A and 75 ml of soup B

When we serve some soup, we give it to someone and we no longer have it.  Each turn, we will choose from the four
operations with equal probability 0.25. If the remaining volume of soup is not enough to complete the operation,
we will serve as much as we can.  We stop once we no longer have some quantity of both types of soup.

Note that we do not have the operation where all 100 ml's of soup B are used first.

Return the probability that soup A will be empty first, plus half the probability that A and B become empty at the same time.



Example:
Input: N = 50
Output: 0.625
Explanation:
If we choose the first two operations, A will become empty first. For the third operation, A and B will become empty
at the same time. For the fourth operation, B will become empty first. So the total probability of A becoming empty
first plus half the probability that A and B become empty at the same time, is 0.25 * (1 + 1 + 0.5 + 0) = 0.625.

Notes:

    0 <= N <= 10^9.
    Answers within 10^-6 of the true value will be accepted as correct.


 */

/*
有A，B两种汤。初始每种汤各有N毫升，现有4种操作：

1. A倒出100ml，B倒出0ml
2. A倒出75ml， B倒出25ml
3. A倒出50ml， B倒出50ml
4. A倒出25ml， B倒出75ml

每种操作的概率均等为0.25。如果汤的剩余容量不足完成某次操作，则有多少倒多少。当每一种汤都倒完时停止操作。

求A先倒完的概率，加上A和B同时倒完的概率。
 */
public class LC_0808_SoupServings {
    public double soupServings(int N) {
        int n = N;
        if (n >= 10000) {
            return 1; // because you have 75% cost A more than B.
        }
        if (n % 25 != 0) {
            n = n / 25 + 1;
        } else {
            n = n / 25;
        }
        int[][] options = new int[][]{{4, 0}, {3, 1}, {2, 2}, {1, 3}};
        return dfs(n, n, options, new Double[n + 1][n + 1]);
    }
    private double dfs(int soupA, int soupB, int[][]options, Double[][] mem) {
        if (soupA <= 0) {
            if (soupB > 0) {
                return 1;
            }
            if (soupB <= 0) {
                return 0.5;
            }
        }
        if (soupB <= 0) {
            return 0;
        }
        if (mem[soupA][soupB] != null) {
            return mem[soupA][soupB];
        }
        // 4 options
        double res = 0.0;
        for (int i = 0; i < options.length; i++) {
            int nextA = soupA - options[i][0];
            int nextB = soupB - options[i][1];
            res += 0.25 * dfs(nextA, nextB, options, mem);
        }
        mem[soupA][soupB] = res;
        return res;
    }
}
