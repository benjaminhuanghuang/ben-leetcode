package cn.huang.leetcode;

/*

691. Stickers to Spell Word

 We are given N different types of stickers. Each sticker has a lowercase English word on it.

You would like to spell out the given target string by cutting individual letters from your collection of stickers and rearranging them.

You can use each sticker more than once if you want, and you have infinite quantities of each sticker.

What is the minimum number of stickers that you need to spell out the target? If the task is impossible, return -1.

Example 1:

Input:

["with", "example", "science"], "thehat"

Output:

3

Explanation:

We can use 2 "with" stickers, and 1 "example" sticker.
After cutting and rearrange the letters of those stickers, we can form the target "thehat".
Also, this is the minimum number of stickers necessary to form the target string.

Example 2:

Input:

["notice", "possible"], "basicbasic"

Output:

-1

Explanation:

We can't form the target "basicbasic" from cutting letters from the given stickers.

Note:
stickers has length in the range [1, 50].
stickers consists of lowercase English words (without apostrophes).
target has length in the range [1, 15], and consists of lowercase English letters.
In all test cases, all words were chosen randomly from the 1000 most common US English words, and the target was chosen as a concatenation of two random words.
The time limit may be more challenging than usual. It is expected that a 50 sticker test case can be solved within 35ms on average.
 */
public class LC_0691_StickerstoSpellWord {
    public int minStickers(String[] stickers, String target) {
        int n = target.length(), m = 1 << n; // if target has n chars, there will be m=2^n-1 subset of characters in target
        int[] dp = new int[m];
        for (int i = 0; i < m; i++)
            dp[i] = Integer.MAX_VALUE; // use index 0 - 2^n-1 as bitmaps to represent each subset of all chars in target
        dp[0] = 0; // first thing we know is : dp[empty set] requires 0 stickers,
        for (int i = 0; i < m; i++) { // for every subset i, start from 000...000。（起点这里很重要，因为大的集合往往依赖于小的集合）
            if (dp[i] == Integer.MAX_VALUE) continue;
            for (String s : stickers) { // try use each sticker as an char provider to populate 1 of its superset, to do that:
                int sup = i;//关键代码（下面：在i上面加入一个单词后的效果）
                for (char c : s.toCharArray()) { // for each char in the sticker, try apply it on a missing char in the subset of target
                    for (int r = 0; r < n; r++) {
                        if (target.charAt(r) == c && ((sup >> r) & 1) == 0) {  //如果target中包含字符c , 并且sup中相应位置没有c。
                            sup |= 1 << r;//在sup中相应位置，加入c，形成新的集合。
                            break;
                        }
                    }
                }
                // after you apply all possible chars in a sticker, you get an superset that take 1 extra sticker than subset
                // would take, so you can try to update the superset's minsticker number with dp[sub]+1;
                dp[sup] = Math.min(dp[sup], dp[i] + 1);//判断是否需要替换原来sup中的值。
            }
        }
        return dp[m - 1] != Integer.MAX_VALUE ? dp[m - 1] : -1;
    }
}
