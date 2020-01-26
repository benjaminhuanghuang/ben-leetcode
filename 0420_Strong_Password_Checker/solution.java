package cn.huang.leetcode;

import java.util.HashMap;

/*
420. Strong Password Checker

A password is considered strong if below conditions are all met:

    It has at least 6 characters and at most 20 characters.
    It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
    It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong,
    assuming other conditions are met).

Write a function strongPasswordChecker(s), that takes a string s as input, and return the MINIMUM change required
to make s a strong password. If s is already strong, return 0.

Insertion, deletion or replace of any one character are all considered as one change.
 */
public class LC_0420_StrongPasswordChecker {
    /*
    长度、含小写、大写、数字、不能有连续重复三个的字符，共5个规则。
    */
    public int strongPasswordChecker_Error(String s) {
        String res = "";
        HashMap<String, Integer> hm = new HashMap<String, Integer>();
        int metNum = 0;
        int maxRepNum = 1;

        int len = s.length();
        if (len >= 6 && len <= 20) {
            hm.put("isLength", 1);
            metNum++;
        } else {
            hm.put("isLength", 0);
        }
        for (int i = 0; i < len; i++) {
            char c = s.charAt(i);
            if (Character.isLowerCase(c)) {
                if (!hm.containsKey("isLowercase")) {
                    hm.put("isLowercase", 1);
                    metNum++;
                }
            } else if (Character.isUpperCase(c)) {
                if (!hm.containsKey("isUppercase")) {
                    hm.put("isUppercase", 1);
                    metNum++;
                }
            } else if (Character.isDigit(c)) {
                if (!hm.containsKey("isDigit")) {
                    hm.put("isDigit", 1);
                    metNum++;
                }
            }
            if (!hm.containsKey("isRepeat3")) {
                if (i < len - 1 && s.charAt(i) == s.charAt(i + 1)) {
                    maxRepNum++;
                    if (maxRepNum >= 3) {
                        hm.put("isRepeat3", 1);
                    }
                } else {
                    maxRepNum = 1;
                }
            }
        }
        if (!hm.containsKey("isRepeat3")) {
            metNum++;
        }

        int minimum = 5 - metNum; //get Minimum change
        return minimum;
    }

    /*
    https://yuncoong.gitbooks.io/leetcode/content/420.html
    1. Length problem:

        len < 6: insert
        len > 20: delete

    2. Missing case: replace / insert
    3. repeat: replace / delete / insert
    4. First, solve len < 6 together with missing case problem with insert
    5. Then solve the over length problem with repeat problem

        how to decide when to use replace or delete?
            to ensure the minimum change, not delete number repeat elements to <= 2, but to first reduce the number to the closest 3m + 2 value, where m will be the number of replace we need to do.
                for interger A % 3 == 0 ----> A -= 1 to get to 3m + 2, update the over_len -= 1
                for interger A % 3 == 1 -----> A -= 2 to get to 3m + 2, update the over_len -= 2
            After transforming all the repeat count number to 3m + 2 form, check if overlen > 0, then directly reduce the repeat count number to ( countnumber < 2 or overlen == 0)
            then do replace on the left repeat problem



     */
    public int strongPasswordChecker_better(String s) {
        int res = 0, needLower = 1, needUpper = 1, needDigit = 1;

        char[] chars = s.toCharArray();
        int[] arr = new int[chars.length];

        for (int i = 0; i < arr.length; ) {
            if (Character.isLowerCase(chars[i])) needLower = 0;
            if (Character.isUpperCase(chars[i])) needUpper = 0;
            if (Character.isDigit(chars[i])) needDigit = 0;

            int j = i;
            while (i < chars.length && chars[i] == chars[j])
                i++;
            arr[j] = i - j;
        }

        int total_missing = (needLower + needUpper + needDigit);

        if (arr.length < 6) {
            res += total_missing + Math.max(0, 6 - (arr.length + total_missing));

        } else {
            int over_len = Math.max(arr.length - 20, 0), left_over = 0;
            res += over_len;

            for (int k = 1; k < 3; k++) {
                for (int i = 0; i < arr.length && over_len > 0; i++) {
                    if (arr[i] < 3 || arr[i] % 3 != (k - 1))
                        continue;
                    arr[i] -= Math.min(over_len, k);
                    over_len -= k;
                }
            }

            for (int i = 0; i < arr.length; i++) {
                if (arr[i] >= 3 && over_len > 0) {
                    int need = arr[i] - 2;
                    arr[i] -= over_len;
                    over_len -= need;
                }

                if (arr[i] >= 3)
                    left_over += arr[i] / 3;
            }

            res += Math.max(total_missing, left_over);
        }

        return res;

    }
}
