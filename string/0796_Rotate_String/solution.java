package cn.huang.leetcode;

/*
    796. Rotate String
 */
public class LC_0796_RotateString {
    public boolean rotateString(String A, String B) {
        if (A.length() != B.length())
            return false;
        if (A.equals(B)) {
            return true;
        }
        return (A + A).indexOf(B) > 0;
    }
}
