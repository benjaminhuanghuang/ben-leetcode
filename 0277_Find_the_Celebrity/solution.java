package cn.huang.leetcode;

/*
277. Find the Celebrity

Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, there may exist one celebrity.

The definition of a celebrity is that all the other n - 1 people know him/her but he/she does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do
is to ask questions like: "Hi, A. Do you know B?" to get information of whether A knows B. You need to find out the
celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).

You are given a helper function bool knows(a, b) which tells you whether A knows B. Implement a function int
findCelebrity(n), your function should minimize the number of calls to knows.

Note: There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a
celebrity in the party. If there is no celebrity, return -
 */

/*
    https://www.youtube.com/watch?v=QDehNYXlCAg

*/
public class LC_0277_FindtheCelebrity {
    private boolean knows(int a, int b) {
        return false;
    }

    public int findCelebrity(int n) {
        int candidate = 0;
        // find a candidate
        for (int i = 1; i < n; i++) {
            // if candidate knows i, this candidate is not celebrity
            if (knows(candidate, i)) {
                candidate = i;
            }
            // else i is not candidate
        }
        // Make sure if the candidate is a celebrity by on pass
        // 无法确认candidate之前的人都认识candidate
        for (int i = 0; i < n; i++) {
            if (candidate == i) {
                continue;
            }
            if (!knows(i, candidate) || knows(candidate, i)) {
                return -1;
            }
        }
        return candidate;
    }
}
