package cn.huang.leetcode;

import java.util.HashMap;
import java.util.Map;
import java.util.Random;

/*
710. Random Pick with Blacklist

Given a blacklist B containing unique integers from [0, N), write a function to return a uniform random integer
from [0, N) which is NOT in B.

Optimize it such that it minimizes the call to system’s Math.random().

Note:

    1 <= N <= 1000000000
    0 <= B.length < min(100000, N)
    [0, N) does NOT include N. See interval notation.

Example 1:

Input:
["Solution","pick","pick","pick"]
[[1,[]],[],[],[]]
Output: [null,0,0,0]

Example 2:

Input:
["Solution","pick","pick","pick"]
[[2,[]],[],[],[]]
Output: [null,1,1,1]

Example 3:

Input:
["Solution","pick","pick","pick"]
[[3,[1]],[],[],[]]
Output: [null,0,0,2]

Example 4:

Input:
["Solution","pick","pick","pick"]
[[4,[2]],[],[],[]]
Output: [null,1,3,1]

Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has two arguments,
N and the blacklist B. pick has no arguments. Arguments are always wrapped with a list, even if there aren't any.

 */

/*
题目大意：给一个N,表示一个范围[0,N),给一个黑名单列表blacklist,其中blacklist中的元素在[0,N)范围内，调用pick方法的时候随机返回一个数，这个数满足

    在[0,N)范围
    不在blacklist内
    要随机

思路：构造一个集合M，该M是 [0,N) - blacklist 的一个集合，调用pick时，返回[0,M)的一个随机数并根据这个随机数从集合M中取数即可。
 */
public class LC_0710_RandomPickwithBlacklist {
    class Solution {
        int M;
        Map<Integer, Integer> map;
        Random r;

        public Solution(int N, int[] blacklist) {
            M = N - blacklist.length;
            map = new HashMap<>();
            r = new Random();
            for (int tmp : blacklist) {
                map.put(tmp, -1);
            }

            for (int tmp : blacklist) {
                if (tmp < M) {
                    while (map.containsKey(N - 1)) {
                        N--;
                    }
                    map.put(tmp, --N);
                }
            }
        }

        public int pick() {
            // random in [0,N) not in blacklist
            int p = r.nextInt(M);
            if (map.containsKey(p)) return map.get(p);
            return p;
        }
    }

}
