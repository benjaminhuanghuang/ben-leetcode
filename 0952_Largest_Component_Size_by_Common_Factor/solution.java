package cn.huang.leetcode;

import java.util.HashMap;
import java.util.Map;

/*

952. Largest Component Size by Common Factor

Given a non-empty array of unique positive integers A, consider the following graph:

There are A.length nodes, labelled A[0] to A[A.length - 1];
There is an edge between A[i] and A[j] if and only if A[i] and A[j] share a common factor greater than 1.
Return the size of the largest connected component in the graph.



Example 1:

Input: [4,6,15,35]
Output: 4

Example 2:

Input: [20,50,9,63]
Output: 2

Example 3:

Input: [2,3,6,7,4,12,21,39]
Output: 8

Note:

1 <= A.length <= 20000
1 <= A[i] <= 100000
 */
public class LC_0952_LargestComponentSizebyCommonFactor {
    /*
    https://zxi.mytechroad.com/blog/graph/leetcode-952-largest-component-size-by-common-factor/
     */
    public int largestComponentSize(int[] A) {
        int n = Integer.MIN_VALUE;
        for (int i = 0; i < A.length; i++) {
            if (A[i] > n) {
                n = A[i];
            }
        }
        UnionFind dsu = new UnionFind(n + 1);
        for (int a : A) {
            int t = (int) (Math.sqrt(a));
            for (int k = 2; k <= t; ++k)
                if (a % k == 0) {
                    dsu.union(a, k);
                    dsu.union(a, a / k);
                }
        }
        Map<Integer, Integer> c = new HashMap<>();
        int ans = 1;
        for (int a : A) {
            c.put(dsu.find(a), c.getOrDefault(dsu.find(a), 0) + 1);
            ans = Math.max(ans, c.get(dsu.find(a)));
        }
        return ans;
    }

     class UnionFind {
        private int[] root;

        public UnionFind(int n) {
            this.root = new int[n];
            for (int i = 0; i < n; ++i) {
                this.root[i] = i;
            }
        }

        public void union(int i, int j) {
            root[find(i)] = root[find(j)];
        }

        public int find(int x) {
            if (root[x] != x)
                root[x] = find(root[x]);
            return root[x];
        }
    }
}
