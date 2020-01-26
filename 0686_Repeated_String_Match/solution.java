package cn.huang.leetcode;

/*
    686. Repeated String Match
 */
public class LC_0686_RepeatedStringMatch {
    /*
     case "a" "aa"
     */
    public int repeatedStringMatch(String A, String B) {
        StringBuilder sb = new StringBuilder(A);
        int count = 1;
        while (sb.length() < B.length()) {
            sb.append(A);
            count++;
        }

        if (sb.indexOf(B) >= 0) {
            return count;
        }
        sb.append(A);
        count++;
        if (sb.indexOf(B) >= 0) {
            return count;
        }
        return -1;
    }
}
