package cn.huang.leetcode;

import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

/*
846. Hand of Straights

Alice has a hand of cards, given as an array of integers.

Now she wants to rearrange the cards into groups so that each group is size W, and consists of W consecutive cards.

Return true if and only if she can.



Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].

Example 2:

Input: hand = [1,2,3,4,5], W = 4
Output: false
Explanation: Alice's hand can't be rearranged into groups of 4.



Note:

    1 <= hand.length <= 10000
    0 <= hand[i] <= 10^9
    1 <= W <= hand.length


 */
public class LC_0846_HandofStraights
{
    public boolean isNStraightHand(int[] hand, int W) {
        int n = hand.length;
        if (n < W || n%W != 0) return false;
        int groups = n/W;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int card: hand)
            pq.offer(card);

        for (int i = 0; i < groups; i++) {
            int first = pq.poll();
            for (int j = 1; j < W; j++) {
                // if (pq.remove(first+j)) continue;
                if (pq.contains(first+j))
                    pq.remove(first+j);
                else
                    return false;
            }
        }
        return true;
    }
}
