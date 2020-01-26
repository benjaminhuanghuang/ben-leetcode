package cn.huang.leetcode;

import java.util.*;

/*
950. Reveal Cards In Increasing Order
In a deck of cards, every card has a unique integer.  You can order the deck in any order you want.

Initially, all the cards start face down (unrevealed) in one deck.

Now, you do the following steps repeatedly, until all cards are revealed:

Take the top card of the deck, reveal it, and take it out of the deck.
If there are still cards in the deck, put the next top card of the deck at the bottom of the deck.
If there are still unrevealed cards, go back to step 1.  Otherwise, stop.
Return an ordering of the deck that would reveal the cards in increasing order.

The first entry in the answer is considered to be the top of the deck.


Example 1:

Input: [17,13,11,2,3,5,7]
Output: [2,13,3,11,5,17,7]
Explanation:
We get the deck in the order [17,13,11,2,3,5,7] (this order doesn't matter), and reorder it.

After reordering, the deck starts as [2,13,3,11,5,17,7], where 2 is the top of the deck.
We reveal 2, and move 13 to the bottom.  The deck is now [3,11,5,17,7,13].
We reveal 3, and move 11 to the bottom.  The deck is now [5,17,7,13,11].
We reveal 5, and move 17 to the bottom.  The deck is now [7,13,11,17].
We reveal 7, and move 13 to the bottom.  The deck is now [11,17,13].
We reveal 11, and move 17 to the bottom.  The deck is now [13,17].
We reveal 13, and move 17 to the bottom.  The deck is now [17].
We reveal 17.
Since all the cards revealed are in increasing order, the answer is correct.


Note:

1 <= A.length <= 1000
1 <= A[i] <= 10^6
A[i] != A[j] for all i != j

 */
public class LC_0950_RevealCardsInIncreasingOrder {
    //https://redtongue.coding.me/2018/12/02/950-Reveal-Cards-In-Increasing-Order/
    /*
    可以用输出来反推输入，输出可以看成是一个队列,记为queue，最后入队的是最大值，最先入队的是最小值。
    从输入到输出的逻辑是先把deck的第一个元素放入queue，然后第二个元素放入deck的最后；

    那么从输出反推的输入的逻辑就是先把deck的最后一个元素放入到deck的第一个位置，然后再把queue的最后一个元素放入deck。
     */
    public int[] deckRevealedIncreasing(int[] deck) {

        List<Integer> res = new ArrayList<>();
        Arrays.sort(deck);
        LinkedList<Integer> queue = new LinkedList<>();  // ordered cards
        for(int card: deck)
            queue.offer(card);

        while(!queue.isEmpty())
        {
            int card = queue.pollLast();
            if(res.size() == 0)
                res.add(card);
            else
            {
                res.add(0,  res.get(res.size()-1));
                res.remove(res.size()-1);
                res.add(0, card);
            }

        }
        int[] ret = new int[res.size()];
        int i = 0;
        for (Integer e : res)
            ret[i++] = e;
        return ret;
    }
}
