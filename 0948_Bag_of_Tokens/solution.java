package cn.huang.leetcode;
/*
948. Bag of Tokens

You have an initial power P, an initial score of 0 points, and a bag of tokens.

Each token can be used at most once, has a value token[i], and has potentially two ways to use it.

    If we have at least token[i] power, we may play the token face up, losing token[i] power, and gaining 1 point.
    If we have at least 1 point, we may play the token face down, gaining token[i] power, and losing 1 point.

Return the largest number of points we can have after playing any number of tokens.



Example 1:

Input: tokens = [100], P = 50
Output: 0

Example 2:

Input: tokens = [100,200], P = 150
Output: 1

Example 3:

Input: tokens = [100,200,300,400], P = 200
Output: 2



Note:

    tokens.length <= 1000
    0 <= tokens[i] < 10000
    0 <= P < 10000


 */

import java.util.Arrays;

/*
你有两个属性：power和points（初始为0），并且有一些token，每个token自己有一个值（token[i]）。你可以对一个token做如下两种操作之一（或者可以什么都不做）：

    face up：如果你的power >= token[i]，则可以令power -= token[i]，且points++
    face down：如果你的points > 0，则可以令power += token[i]，且points--

问你可以用这些token达到的最大points数量是多少。

给一个数组表示coins with power和一个initial powere P. 现在规则是:

    可以用手里现存的power去买数组中的一个coin.
    也可以用手里的coin去跟数组中的任意一个coin作交换.

现在问玩家最多能得到几个coin.

解法就是greedy, 花最少的power去买coin, 然后买到之后换power最大的coin. 因为最后要求的是最多能得到几个coin, 所以只要手里power够,
就先不停地买买买. 每次买完记得更新res.
 */
public class LC_0948_BagofTokens {
    public int bagOfTokensScore(int[] tokens, int P) {
        Arrays.sort(tokens);
        int low = 0, high = tokens.length - 1;
        int points = 0, ans = 0;
        while (low <= high && (P >= tokens[low] || points > 0)) {
            while (low <= high && P >= tokens[low]) {
                P -= tokens[low++];
                points++;
            }

            ans = Math.max(ans, points);
            if (low <= high && points > 0) {
                P += tokens[high--];
                points--;
            }
        }

        return ans;
    }

    int bagOfTokensScore2(int[] tokens, int P) {
        if (tokens.length == 0)
            return 0;
        Arrays.sort(tokens);
        if (tokens[0] > P)
            return 0;
        int score = 0;

        int i = 0, j = tokens.length - 1, max = 1;
        while (i < j) {
            while (P >= tokens[i]) {
                P -= tokens[i];
                ++score;
                ++i;
                max = Math.max(max, score);
            }
            if (i < j) {
                P += tokens[j];
                --score;
                --j;
            }
        }
        return max;
    }
}
