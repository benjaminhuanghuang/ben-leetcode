package cn.huang.leetcode;

/*
374. Guess Number Higher or Lower
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
Example :

Input: n = 10, pick = 6
Output: 6
 */
public class LC_0374_GuessNumberHigherorLower {
    public int guessNumber(int n) {
        int start = 1;
        int end = n;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (guess(mid) == -1) {
                end = mid;
            } else if (guess(mid) == 1) {
                start = mid;
            } else {
                return mid;
            }
        }
        if (guess(start) == 0)
            return start;
        if (guess(end) == 0)
            return end;
        return -1;
    }

    //return -1 if my number is lower, 1 if my number is higher, otherwise return 0
    int guess(int num) {
        return 0;
    }
}
