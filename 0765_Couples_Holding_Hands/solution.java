package cn.huang.leetcode;

/*
765. Couples Holding Hands

 N couples sit in 2N seats arranged in a row and want to hold hands. We want to know the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.

The people and seats are represented by an integer from 0 to 2N-1, the couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2N-2, 2N-1).

The couples' initial seating is given by row[i] being the value of the person who is initially sitting in the i-th seat.

Example 1:

Input: row = [0, 2, 1, 3]
Output: 1
Explanation: We only need to swap the second (row[1]) and third (row[2]) person.

Example 2:

Input: row = [3, 2, 0, 1]
Output: 0
Explanation: All couples are already seated side by side.

Note:

    len(row) is even and in the range of [4, 60].
    row is guaranteed to be a permutation of 0...len(row)-1.

 */
public class LC_0765_CouplesHoldingHands {
    /*
    http://www.cnblogs.com/grandyang/p/8716597.html
    ，一个数‘异或’上1就是其另一个位，如果是偶数的话，最后位是0，‘异或’上1等于加了1，变成了可以的成对奇数。
    如果是奇数的话，最后位是1，‘异或’上1后变为了0，变成了可以的成对偶数。
     */
    public int minSwapsCouples(int[] row) {
        int res = 0, n = row.length;
        for (int i = 0; i < n; i += 2) {
            if (row[i + 1] == (row[i] ^ 1)) continue;
            ++res;
            for (int j = i + 1; j < n; ++j) {
                if (row[j] == (row[i] ^ 1)) {
                    row[j] = row[i + 1];
                    row[i + 1] = row[i] ^ 1;
                    break;
                }
            }
        }
        return res;
    }

    /*
    https://blog.csdn.net/u014688145/article/details/79057475
     */
    public int minSwapsCouples2(int[] row) {
        int n = row.length;
        int ans = 0;
        for (int i = 0; i < n; i += 2) {
            int dest;
            if ((row[i] & 1) == 0)
                dest = row[i] + 1;
            else
                dest = row[i] - 1;
            if (row[i + 1] == dest)
                continue;
            ans++;
            for (int j = i + 2; j < n; ++j) {
                if (row[j] == dest) {
                    int tmp = row[i + 1];
                    row[i + 1] = row[j];
                    row[j] = tmp;
                    break;
                }
            }
        }
        return ans;
    }
}
