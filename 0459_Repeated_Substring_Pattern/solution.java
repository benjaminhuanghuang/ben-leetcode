package cn.huang.leetcode;

/*
459. Repeated Substring Pattern
 */
public class LC_0459_RepeatedSubstringPattern {
    public static boolean repeatedSubstringPattern(String s) {

        int len = s.length();
        //i表示将s等分成i份，并且从小到大遍历，这样子字符串从长到短，可以节省判断次数
        for (int i = 2; i <= len; i++) {
            //必须整除才可以
            if (len % i == 0) {
                int count = len / i, j;
                //遍历分成的几份子串是否完全相等，相等即表明可分
                for (j = 0; j < i - 1; j++) {
                    if (!s.substring(j * count, (j + 1) * count).equals(s.substring((j + 1) * count, (j + 2) * count)))
                        break;
                }
                if (j == i - 1)
                    return true;
            }
        }
        return false;
    }

    public static boolean repeatedSubstringPattern_2(String str) {

        int len = str.length();
        for (int i = len / 2; i >= 1; i--) {
            if (len % i == 0) {
                int m = len / i;
                String subS = str.substring(0, i);
                int j;
                for (j = 1; j < m; j++) {
                    if (!subS.equals(str.substring(j * i, i + j * i))) break;
                }
                if (j == m)
                    return true;
            }
        }
        return false;
    }
}
