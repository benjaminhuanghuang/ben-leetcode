package cn.huang.leetcode;

/*
592. Fraction Addition and Subtraction

Given a string representing an expression of fraction addition and subtraction, you need to return the calculation result in string format. The final result should be irreducible fraction. If your final result is an integer, say 2, you need to change it to the format of fraction that has denominator 1. So in this case, 2 should be converted to 2/1.

Example 1:

Input:"-1/2+1/2"
Output: "0/1"

Example 2:

Input:"-1/2+1/2+1/3"
Output: "1/3"

Example 3:

Input:"1/3-1/2"
Output: "-1/6"

Example 4:

Input:"5/3+1/3"
Output: "2/1"

Note:

    The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
    Each fraction (input and output) has format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
    The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1,10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
    The number of given fractions will be in the range [1,10].
    The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.



 */
public class LC_0592_FractionAdditionandSubtraction {
    /*
    http://bgmeow.xyz/2017/06/08/LeetCode-592/
     */
    public String fractionAddition(String expression) {
        int currNume = 0;
        int currDeno = 1;
        if (!expression.startsWith("-")) {
            expression = "+" + expression;
        }
        int pos1 = 0;
        int length = expression.length();
        while (pos1 < length) {
            int pos2 = pos1;
            while (pos2 < length && expression.charAt(pos2) != '/') {
                pos2++;
            }
            int nume = Integer.parseInt(expression.substring(pos1, pos2));
            pos1 = ++pos2;
            while (pos2 < length && expression.charAt(pos2) >= '0' && expression.charAt(pos2) <= '9') {
                pos2++;
            }
            int deno = Integer.parseInt(expression.substring(pos1, pos2));
            pos1 = pos2;

            // add fractions
            int combineDeno = currDeno * deno;
            currNume *= deno;
            nume *= currDeno;
            int combineNume = currNume + nume;
            int divisor = getDivisor(Math.abs(combineDeno), Math.abs(combineNume));
            currNume = combineNume / divisor;
            currDeno = combineDeno / divisor;
        }
        return currNume + "/" + currDeno;
    }

    private int getDivisor(int m, int n) {
        int temp;
        if (m < n) {
            temp = m;
            m = n;
            n = temp;
        }
        if (n == 0) {
            return m;
        }
        while (m % n != 0) {
            temp = n;
            n = m % n;
            m = temp;
        }
        return n;
    }
}
