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
https://www.youtube.com/watch?v=MgvCf2SKnzk
如何优化 Time Limit Exceeded 
*/




public class LC_0825_FriendsOfAppropriateAges {
  public int numFriendRequests_TLE(int[] ages) {
    if (ages == null || ages.length <= 1) {
      return 0;
    }

    int n = ages.length;
    int res = 0;

    // O(N^2) , n = 20000, cause TLE
    for (int i =0;i < n; i++)
    {
      for (int j =0;j < n; j++)
      {
        if(good(ages[i], ages[j] ))
          res++;
      }
    }
    return res;
  }

  public int numFriendRequests(int[] ages) {
    if (ages == null || ages.length <= 1) {
      return 0;
    }
    // 一个map记录此年龄的有多少人
    HashMap<Integer, Integer> count = new HashMap<>();
    for (int age : ages){
      count.put(age, count.getOrDefault(age,0) + 1);
    }
    int res = 0;
    for ( Integer a: count.keySet()){
      for ( Integer b: count.keySet()){
        if(good(a, b)){
          res += count.get(a) * (count.get(b) - a==b?1:0);
        }
      }
    }
    
    return res;
  }

  boolean good(int A, int B) {
    if (B <= 0.5 * A + 7) {
      return false;
    }
    if (B < B) return false;
    if (B > 100 && A < 100) {
      return false;
    }
    return true;
  }
}
