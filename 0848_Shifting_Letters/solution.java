package cn.huang.leetcode;
/*
848. Shifting Letters

We have a string S of lowercase letters, and an integer array shifts.

Call the shift of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').

For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.

Now for each shifts[i] = x, we want to shift the first i+1 letters of S, x times.

Return the final string after all such shifts to S are applied.

Example 1:

Input: S = "abc", shifts = [3,5,9]
Output: "rpl"
Explanation:
We start with "abc".
After shifting the first 1 letters of S by 3, we have "dbc".
After shifting the first 2 letters of S by 5, we have "igc".
After shifting the first 3 letters of S by 9, we have "rpl", the answer.

Note:

    1 <= S.length = shifts.length <= 20000
    0 <= shifts[i] <= 10 ^ 9


 */

/*
       给出了一个字符串S，以及和这个字符串等长的数组shifts。定义了一个shift操作：把某个字符在字母表上移动某位（字母’z’再向右移得到’a’）。
       现在遍历shifts，每个操作都是把"当前位数之前的所有字符"移动shift位。求最后得到的字符串。

       如果普通的遍历，在每次遍历的时候再把之前所有shift过的再次shift，那么就会超时。

       所以正确的做法是先求出每个字符串需要shift的次数。即对shifts进行位置之后的求和。得出要shift的位数之后，按照题目给的那种循环去操作就好了。

*/
public class LC_0848_ShiftingLetters {
    public String shiftingLetters(String S, int[] shifts) {
        if (shifts.length == 0 || S == "")
            return S;

        // Important!
        for (int i = shifts.length - 2; i >= 0; i--) {
            shifts[i] = (shifts[i] % 26 + shifts[i + 1] % 26) % 26;
        }

        char[] charArray = S.toCharArray();
        for (int i = 0; i < shifts.length; i++) {
            int c = charArray[i] - 'a' + shifts[i];
            charArray[i] = (char) ('a' + c % 26);
        }
        return String.valueOf(charArray);
    }

    /*
    https://www.youtube.com/watch?v=gOycoA8pOqg
     */
    public String shiftingLetters_better(String S, int[] shifts) {
        if (shifts.length == 0 || S == "")
            return S;

        int c = 0;

        char[] charArray = S.toCharArray();
        for (int i = shifts.length - 1; i >= 0; i--) {
            c += (shifts[i] % 26);
            charArray[i] = (char) ((charArray[i] - 'a' + c) % 26 + 'a');
        }
        return String.valueOf(charArray);
    }
}
