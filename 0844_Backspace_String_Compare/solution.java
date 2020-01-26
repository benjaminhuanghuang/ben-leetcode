package cn.huang.leetcode;

/*
 844	Backspace String Compare
 */
public class LC_0844_BackspaceStringCompare {
    public boolean backspaceCompare(String S, String T) {
        return type(S).equals(type(T));
    }
    private String type(String s) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (c == '#') {
                if (sb.length() > 0)
                    sb.setLength(sb.length() - 1);
            } else {
                sb.append(c);
            }
        }
        return sb.toString();
    }
}
