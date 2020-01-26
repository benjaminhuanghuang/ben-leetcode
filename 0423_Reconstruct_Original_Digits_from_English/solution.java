package cn.huang.leetcode;

import java.util.HashMap;

/*
423. Reconstruct Original Digits from English

Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in
ascending order.

Note:

    Input contains only lowercase English letters.
    Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as
    "abc" or "zerone" are not permitted.
    Input length is less than 50,000.

Example 1:

Input: "owoztneoer"

Output: "012"

Example 2:

Input: "fviefuro"

Output: "45"

 */
public class LC_0423_ReconstructOriginalDigitsfromEnglish {
    /*
    http://www.voidcn.com/article/p-xtdjmope-bmq.html
     */
    public String originalDigits(String s) {
        if (s == null || s.length() == 0) return "";
        int[] count = new int[128];
        for (int i = 0; i < s.length(); i++) count[s.charAt(i)]++;
        int[] num = new int[10];
        num[0] = count['z']; //zero
        num[2] = count['w']; //two
        num[4] = count['u']; //four
        num[6] = count['x']; //fix
        num[8] = count['g']; //eight
        num[1] = count['o'] - count['z'] - count['w'] - count['u']; //one=[o]-zero-two-four
        num[3] = count['h'] - count['g']; //three=[h]-eight
        num[5] = count['v'] - count['s'] + count['x']; //five=[v]-seven
        num[7] = count['s'] - count['x']; //seven=[s]-six
        // nine=[i]-six-eight-five
        num[9] = count['i'] - count['x'] - count['g'] - count['v'] + count['s'] - count['x'];
        String ret = new String();
        for (int i = 0; i < 10; i++) {
            for (int j = num[i]; j > 0; j--) {
                ret += String.valueOf(i);
            }
        }
        return ret;
    }
}
