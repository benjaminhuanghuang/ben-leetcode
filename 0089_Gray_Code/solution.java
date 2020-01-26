package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
89. Gray Code
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code,
print the sequence of gray code. A gray code sequence must begin with 0.

Example 1:

Input: 2
Output: [0,1,3,2]
Explanation:
00 - 0
01 - 1
11 - 3
10 - 2

For a given n, a gray code sequence may not be uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence.

00 - 0
10 - 2
11 - 3
01 - 1

Example 2:

Input: 0
Output: [0]
Explanation: We define the gray code sequence to begin with 0.
             A gray code sequence of n has size = 2n, which for n = 0 the size is 20 = 1.
             Therefore, for n = 0 the gray code sequence is [0].


 */
public class LC_0089_GrayCode {
    /*
     start with 0, use an array to store all visited number.
     change the first bit of the number, if it has not visited, add to visited array and continue with this new number.
     If it has visited, just return and try changing the second bit of the number.
     00 to visited array
     00 try change first bit -> 01    add 01 to visited array
     01 try change first bit -> 00   already visited
     01 try change second bit -> 11    add 11 to visited
     11 try change first bit -> 10 add 10 to visited
     */
    public List<Integer> grayCode(int n) {
        List<Integer> res = new ArrayList<>();
        int count = 1 << n;
        boolean[] visited = new boolean[count];

        int start = 0;

        while (count-- > 0)    // no need to use i < moves here
        {
            res.add(start);
            visited[start] = true;
            for (int i = 0; i < n; i++)
            {
                int next = start ^ (1 << i);  //only one bit is different
                if (visited[next])
                    continue;
                start = next;
                break;
            }
        }
        return res;
    }
}
