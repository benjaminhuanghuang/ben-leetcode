package cn.huang.leetcode;
/*
825. Friends Of Appropriate Ages

Some people will make friend requests. The list of their ages is given and ages[i] is the age of the ith person.

Person A will NOT friend request person B (B != A) if any of the following conditions are true:

    age[B] <= 0.5 * age[A] + 7
    age[B] > age[A]
    age[B] > 100 && age[A] < 100

Otherwise, A will friend request B.

Note that if A requests B, B does not necessarily request A.  Also, people will not friend request themselves.

How many total friend requests are made?

Example 1:

Input: [16,16]
Output: 2
Explanation: 2 people friend request each other.

Example 2:

Input: [16,17,18]
Output: 2
Explanation: Friend requests are made 17 -> 16, 18 -> 17.

Example 3:

Input: [20,30,100,110,120]
Output:
Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100.



Notes:

    1 <= ages.length <= 20000.
    1 <= ages[i] <= 120.


 */

import java.util.Arrays;
import java.util.HashMap;

/*
给定一个数组作为一群人的年龄分布，判断这群人中一共可以发送最多多少好友申请。
 */
public class LC_0825_FriendsOfAppropriateAges {
    public int numFriendRequests(int[] ages) {
        if (ages == null || ages.length <= 1) {
            return 0;
        }
        // 一个map记录此年龄的人可以发送的请求个数
        HashMap<Integer, Integer> map = new HashMap<>();
        int ans = 0; // 进行排序，在内部循环的时候会用到
        Arrays.sort(ages);
        for (int i = 0; i < ages.length; i++) { // 重用以前数据
            if (map.containsKey(ages[i])) {
                ans += map.get(ages[i]);
                continue;
            } // 计算此年龄的人可以发送的请求数
            int sum = 0;
            for (int j = 0; j < ages.length && ages[j] <= ages[i]; j++) {
                if (i != j && good(ages[i], ages[j])) {
                    ++sum;
                }
            }
            map.put(ages[i], sum);
            ans += sum;
        }
        return ans;
    }

    boolean good(int A, int B) {
        if (B <= 0.5 * A + 7) {
            return false;
        }
        if (B > 100 && A < 100) {
            return false;
        }
        return true;
    }
}
