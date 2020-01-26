package cn.huang.leetcode;

import java.util.LinkedList;
import java.util.Queue;

/*
649. Dota2 Senate
 In the world of Dota2, there are two parties: the Radiant and the Dire.

The Dota2 senate consists of senators coming from two parties. Now the senate wants to make a decision about a change
in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise one
of the two rights:

    Ban one senator's right:
    A senator can make another senator lose all his rights in this and all the following rounds.
    Announce the victory:
    If this senator found the senators who still have rights to vote are all from the same party, he can announce the
    victory and make the decision about the change in the game.

Given a string representing each senator's party belonging. The character 'R' and 'D' represent the Radiant party and
the Dire party respectively. Then if there are n senators, the size of the given string will be n.

The round-based procedure starts from the first senator to the last senator in the given order. This procedure will
last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.

Suppose every senator is smart enough and will play the best strategy for his own party, you need to predict which
party will finally announce the victory and make the change in the Dota2 game. The output should be Radiant or Dire.

Example 1:

Input: "RD"
Output: "Radiant"
Explanation: The first senator comes from Radiant and he can just ban the next senator's right in the round 1.
And the second senator can't exercise any rights any more since his right has been banned.
And in the round 2, the first senator can just announce the victory since he is the only guy in the senate who can vote.

Example 2:

Input: "RDD"
Output: "Dire"
Explanation:
The first senator comes from Radiant and he can just ban the next senator's right in the round 1.
And the second senator can't exercise any rights anymore since his right has been banned.
And the third senator comes from Dire and he can ban the first senator's right in the round 1.
And in the round 2, the third senator can just announce the victory since he is the only guy in the senate who can vote.

Note:

    The length of the given string will in the range [1, 10,000].

 */
public class LC_0649_Dota2Senate {
    /*
    可以用两个队列queue，把各自阵营的位置存入不同的队列里面，然后进行循环，每次从两个队列各取一个位置出来，看其大小关系，
    小的那个说明在前面，就可以把后面的那个Ban掉，所以我们要把小的那个位置要加回队列里面，
    但是不能直接加原位置，因为下一轮才能再轮到他来Ban，所以我们要加上一个n，再排入队列。这样当某个队列为空时，推出循环，我们返回不为空的那个阵营，
     */
    public String predictPartyVictory(String senate) {
        int n = senate.length();
        Queue<Integer> q1 = new LinkedList<>();
        Queue<Integer> q2 = new LinkedList<>();

        for (int i = 0; i < n; ++i) {
            if (senate.charAt(i) == 'R')
                q1.offer(i);
            else
                q2.offer(i);
        }
        while (!q1.isEmpty() && !q2.isEmpty()) {
            int i = q1.poll();
            int j = q2.poll();
            if (i < j)
                q1.offer(i + n);
            else
                q2.offer(j + n);
        }
        return (q1.size() > q2.size()) ? "Radiant" : "Dire";
    }
}
