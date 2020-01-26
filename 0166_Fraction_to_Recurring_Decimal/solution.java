package cn.huang.leetcode;

import java.util.HashMap;

/*
166. Fraction to Recurring Decimal

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"

Example 2:

Input: numerator = 2, denominator = 1
Output: "2"

Example 3:

Input: numerator = 2, denominator = 3
Output: "0.(6)"


 */
public class LC_0166_FractiontoRecurringDecimal {
    public String fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }

        StringBuilder resBuilder = new StringBuilder();
        HashMap hashtable = new HashMap<Long, Integer>();

        boolean sign = (numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0);
        long denominatorlong = Math.abs((long) denominator);
        long numeratorlong = Math.abs((long) numerator);

        // before .
        resBuilder.append(numeratorlong / denominatorlong);

        long remain = numeratorlong % denominatorlong;

        // add .
        if (remain != 0) {
            resBuilder.append('.');
        }

        // after .
        int count = resBuilder.length();
        while (remain != 0) {
            hashtable.put(remain, count++);
            resBuilder.append((remain * 10) / denominatorlong);
            long nextRemain = (remain * 10) % denominatorlong;
            if (hashtable.containsKey(nextRemain)) {
                resBuilder.insert((int) (hashtable.get(nextRemain)), '(');
                resBuilder.append(')');
                break;
            }

            remain = nextRemain;
        }
        if (sign) {
            resBuilder.insert(0, '-');
        }
        return resBuilder.toString();
    }
}
