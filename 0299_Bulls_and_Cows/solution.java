package cn.huang.leetcode;

import java.util.HashMap;

/*

299. Bulls and Cows

You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend
to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits
in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match
the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints
to eventually derive the secret number.

Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and
B to indicate the cows.

Please note that both secret number and friend's guess may contain duplicate digits.

Example 1:

Input: secret = "1807", guess = "7810"

Output: "1A3B"

Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.

Example 2:

Input: secret = "1123", guess = "0111"

Output: "1A1B"

Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.

Note: You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.
 */
public class LC_0299_BullsandCows {
    public String getHint1(String secret, String guess) {
        int countBull = 0;
        int countCow = 0;

        HashMap<Character, Integer> map = new HashMap<Character, Integer>();

        //check bull
        for (int i = 0; i < secret.length(); i++) {
            char c1 = secret.charAt(i);
            char c2 = guess.charAt(i);

            if (c1 == c2) {
                countBull++;
            } else {
                if (map.containsKey(c1)) {
                    int freq = map.get(c1);
                    freq++;
                    map.put(c1, freq);
                } else {
                    map.put(c1, 1);
                }
            }
        }

        //check cow
        for (int i = 0; i < secret.length(); i++) {
            char c1 = secret.charAt(i);
            char c2 = guess.charAt(i);

            if (c1 != c2) {
                if (map.containsKey(c2)) {
                    countCow++;
                    if (map.get(c2) == 1) {
                        map.remove(c2);
                    } else {
                        int freq = map.get(c2);
                        freq--;
                        map.put(c2, freq);
                    }
                }
            }
        }

        return countBull + "A" + countCow + "B";
    }

    public String getHint(String secret, String guess) {
        int bulls = 0;
        int cows = 0;
        //而index对应的元素值表示secret中该index出现的次数。
        //如果secret出现一次某个数字，该位置就自增1，如果此时该位置小于0，就说明这个数字在guess出现过，因此cows就自增1；
        // guess的处理和secret类似，区别就是index对应元素需要自减。
        int[] numbers = new int[10];
        for (int i = 0; i < secret.length(); i++) {
            if (secret.charAt(i) == guess.charAt(i))
                bulls++;
            else {
                if (numbers[secret.charAt(i) - '0']++ < 0)
                    cows++;
                if (numbers[guess.charAt(i) - '0']-- > 0)
                    cows++;
            }
        }
        return bulls + "A" + cows + "B";
    }
}
