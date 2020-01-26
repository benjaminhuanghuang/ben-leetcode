package cn.huang.leetcode;

/*
    821	 Shortest Distance to a Character
 */
public class LC_0821_ShortestDistancetoaCharacter {
    /*
    遍历字符串S,遇到与字符C相等就分别向左/右计算其他字符与该字符的距离，如果其他字符就是C或与目标字符的距离更小的话遍历就终止。
     */
    public int[] shortestToChar(String S, char C) {
        int[] store = new int[S.length()];
        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) == C) {
                store[i] = 0;
                left(S, C, store, i);
                right(S, C, store, i);
            }
        }
        return store;
    }

    void left(String S, char C, int[] store, int target) {
        for (int i = target - 1; i >= 0; i--) {
            if (S.charAt(i) == C) break;
            if (store[i] == 0 || store[i] > target - i) store[i] = target - i;
        }
    }

    void right(String S, char C, int[] store, int target) {
        for (int i = target + 1; i < S.length(); i++) {
            if (S.charAt(i) == C) break;
            if (store[i] == 0 || store[i] > i - target) store[i] = i - target;
        }
    }
}
