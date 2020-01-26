package cn.huang.leetcode;

/*
537. Complex Number Multiplication
 Given two strings representing two complex numbers.

You need to return a string representing their multiplication. Note i2 = -1 according to the definition.
 */
public class LC_0537_ComplexNumberMultiplication {
    public String complexNumberMultiply(String a, String b) {
        //the ending index, exclusive.
        int a1 = Integer.parseInt(a.substring(0, a.indexOf("+")));
        int a2 = Integer.parseInt(a.substring(a.indexOf("+") + 1, a.length() - 1));

        int b1 = Integer.parseInt(b.substring(0, b.indexOf("+")));
        int b2 = Integer.parseInt(b.substring(b.indexOf("+") + 1, b.length() - 1));

        int c1 = a1 * b1 - a2 * b2;
        int c2 = a1 * b2 + b1 * a2;

        return new String(c1 + "+" + c2 + "i");
    }
}
