package cn.huang.leetcode;
/*
    791. Custom Sort String
    S and T are strings composed of lowercase letters. In S, no letter occurs more than once.

    S was sorted in some custom order previously. We want to permute the characters of T so that they match the order
    that S was sorted. More specifically, if x occurs before y in S, then x should occur before y in the returned string.

    Return any permutation of T (as a string) that satisfies this property.

    Example :
    Input:
    S = "cba"
    T = "abcd"
    Output: "cbad"
    Explanation:
    "a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a".
    Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba", "cbda" are also valid outputs.

 */
public class LC_0791_CustomSortString {
    /*
        把 T 放入 bucket;
        扫描 S 中的字符，使用 bucket 来构造结果字符串。S
        扫描 bucket，把不在 S 中的剩下的字符加到结果字符串上。
     */
    public String customSortString(String S, String T) {
        char[] SC = S.toCharArray();
        char[] TC = T.toCharArray();
        int[] map = new int[26];
        for (int i = 0; i < TC.length; i++) {
            int index = TC[i] - 'a';
            map[index]++;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < SC.length; i++) {
            int index = SC[i] - 'a';
            while (map[index] > 0) {
                sb.append(SC[i]);
                map[index]--;
            }
        }
        for (int i = 0; i < 26; i++) {
            while (map[i] > 0) {
                sb.append((char) (i + 'a'));
                map[i]--;
            }
        }
        return sb.toString();
    }
}
